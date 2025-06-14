/**
 * @file server.c
 * @author David Chung
 * @brief A server programmed in C. 
 * 
 * @version 4 (16FEB25)
 * < Enabled continuous functionality of server / client 
 * < Added server-side logging functionality
 * < Added server-side custom CLI response functionality
 * < Modularized main. Refactored utility functions into separate files / headers
 * < Added client-side command responses for file_ls  
 * 
 * @date 11JAN25
 *
 */


// TODO: Single exit point

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#include <arpa/inet.h>
//#include <signal.h>
#include "../include/server-help.h"
#include "../include/file-mgmt.h"

#define PORT            8080
#define BUFFER_SIZE     1024                            // Max buffer size
#define LOG_FILE        "server_log.txt"                   // Define *stream pointer for file mgmt funct.
#define FAIL            (-1)
#define END             0

int main() 
{
    signal(SIGINT, exit_signal);                    // Registered interrupt signal for exit (`ctrl + c`)

    int server_fd = 0;
    int client_socket = 0;
    struct sockaddr_in address;
    
    FILE *log_file = fopen(LOG_FILE, "a");          // Open a txt in append-mode
    if (NULL == log_file)
    {
        perror("Failed to open log file");
        return EXIT_FAILURE;
    }

    if (FAIL == initialize_server(&server_fd, &address))
    {
        fclose(log_file);
        return EXIT_FAILURE;
    }

    if (FAIL == accept_client(server_fd, &address, &client_socket))
    {
        close(server_fd);
        fclose(log_file);
        return EXIT_FAILURE;
    }

    handle_client(client_socket, log_file);

    close(client_socket);
    close(server_fd);
    fclose(log_file);
    
    return END;
}
