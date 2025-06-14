/**
 * @file file-mgmt.c
 * @author David Chung
 * @brief Client-side file mgmt function definitions. 
 * 
 * @version 1 (31JAN25)
 * @date 31JAN25
 *
 * > Changed functions to return 0 or -1 to indicate errors
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>                   // write()
#include <dirent.h>                   // Directory Opns 
#include <sys/socket.h>
#include "../include/file-mgmt.h"

#define SERVER_DIR  "server-repo/"  // Server directory
#define BUFFER_SIZE 1024
#define FAIL        (-1)
#define PASS        0

int file_get(int client_socket, const char *filename)
{
    char filepath[BUFFER_SIZE];
    snprintf(filepath, sizeof(filepath), "%s%s", SERVER_DIR, filename);  // Construct full path

    FILE *file = fopen(filepath, "rb");
    if (NULL == file)
    {
        perror("\nError opening file");
        send(client_socket, "ERROR: File not found\n", 22, 0);
        return FAIL;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    // Initiate transmission
    if (send(client_socket, "START", 6, 0) == -1)
    {
        perror("Error sending START signal");
        fclose(file);
        return -1;
    }  

    printf("\nSending file: %s\n", filename);

    // Send file in chunks
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0)
    {
        if (FAIL == send(client_socket, buffer, bytes_read, 0))
        {
            perror("Error sending file data");
            fclose(file);
            return FAIL;
        }
    }

    // Send termination message
    if (send(client_socket, "END", 3, 0) == -1)
    {
        perror("Error sending END signal");
        fclose(file);
        return -1;
    }

    printf("\nFile '%s' sent successfully.\n", filename);
    
    // Close file
    fclose(file);
    printf("\nAwaiting response from client \n");
    return 0;
}

int file_ls(int client_socket)
{
    DIR *dir;
    struct dirent *entry;
    char buffer[BUFFER_SIZE] = {0};
    int file_count = 0;

    // Open server-repo
    dir = opendir(SERVER_DIR);
    if (NULL == dir)
    {
        perror("Failed to open server directory");
        snprintf(buffer, BUFFER_SIZE, "Error: Failed to open server directory.\n");
        send(client_socket, buffer, strlen(buffer), 0);
        return FAIL;
    }

    // Header message for the client
    snprintf(buffer, BUFFER_SIZE, "\nFiles in server directory:\n");
    send(client_socket, buffer, strlen(buffer), 0);

    // Read directory contents
    while (NULL != (entry = readdir(dir)))
    {
        // Skip current (.) and parent (..) directories
        if ((0 == strcmp(entry->d_name, ".")) || (0 == strcmp(entry->d_name, "..")))
        {
            continue;
        }

        snprintf(buffer, BUFFER_SIZE, "%s\n", entry->d_name);
        send(client_socket, buffer, strlen(buffer), 0);
        file_count++;
    }

    closedir(dir);

    // If no files were found, notify the client
    if (0 == file_count)
    {
        snprintf(buffer, BUFFER_SIZE, "Directory is empty!\n");
        send(client_socket, buffer, strlen(buffer), 0);
    }

    return 0; 
}
