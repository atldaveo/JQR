/**
 * @file server-help.c
 * @author David Chung
 * @brief Defines server-side utility functions. 
 * 
 * @version 2 (16FEB25)
 * @date 31JAN25
 *
 * > Added file MGMT operations inside handle_client
 */
#include <stdbool.h>

#include "../include/server-help.h"
#include "../include/file-mgmt.h" 

#define END         0
#define SOCKOPT     1
#define FAIL        (-1)
#define PROTOCOL    0
#define BACKLOGMAX  3
#define RESET       0
//#define GETCMD      "file_get "
//#define LISTCMD     "file_ls"

void exit_signal(int signum)
{
    printf("\nReceived signal %d. Exiting program...\n", signum);
    exit(END);
}

int initialize_server(int *server_fd, struct sockaddr_in *address)
{
    int opt = SOCKOPT;                                        // Option for setting socket options
    *server_fd = socket(AF_INET, SOCK_STREAM, PROTOCOL);       // Create socket
    if (*server_fd == FAIL)                               // -1 indicates error
    {
        perror("Socket creation failed");
        return FAIL;
    }

    // Set socket options to allow reuse of the address and port
    if (FAIL == setsockopt(*server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
    {
        perror("Setsockopt failed");
        return FAIL;
    }

    // Configure the address struct
    address->sin_family = AF_INET;
    address->sin_addr.s_addr = INADDR_ANY;
    address->sin_port = htons(PORT);                    // Rectify endianness

    // Bind the socket to the specified address and port
    if (FAIL == bind(*server_fd, (struct sockaddr*)address, sizeof(*address)))
    {
        perror("Bind failed");
        return FAIL;
    }

    // Listen for incoming connections
    if (FAIL == listen(*server_fd, BACKLOGMAX))
    {
        perror("Listen failed");
        return FAIL;
    }

    printf("\nServer is listening on port %d\n", PORT);
    return END;
}

int accept_client(int server_fd, struct sockaddr_in *address, int *client_socket)
{
    socklen_t addrlen = sizeof(*address);
    // Accept client connection
    *client_socket = accept(server_fd, (struct sockaddr*)address, &addrlen);
    if (FAIL == *client_socket)
    {
        perror("Accept failed");
        return FAIL;
    }

    printf("\nClient connected!\n");
    return END;
}

void handle_client(int client_socket, FILE *log_file)
{
    char buffer[BUFFER_SIZE] = {0};         // Created new buffer for custom client response
    char response[BUFFER_SIZE] = {0};
    const char *exit_cmd = "exit";
    bool running = true;

    fprintf(log_file, "<Start of communication>\n\n");

    while (running)
    {
        // Client-side protocols
        // Read client data
        memset(buffer, RESET, BUFFER_SIZE);                                 // Clear buffer
        int bytes_read = read(client_socket, buffer, BUFFER_SIZE);
        if (0 >= bytes_read)                                            // 0 or neg. number indicates error
        {
            printf("Client disconnected.\n");
            break;
        }

        printf("\nClient says: %s\n", buffer);                          // Print client data
        fprintf(log_file, "Client: %s\n", buffer);                      // Log client data
        fflush(log_file);                                               // Forces contents of buffer to be written into log immediately

        // Check if client wants to exit
        if (0 == strncmp(buffer, exit_cmd, sizeof(*exit_cmd)))
        {
            printf("Client requested to disconnect.\n");
            break;
        }
        
        // Check if client wants to get a file (file_get)
        //DEBUG
        if (0 == strncmp(buffer, "file_get", sizeof("file_get")))
        {
            char filename[BUFFER_SIZE];
            sscanf((buffer + (sizeof("file_get"))), "%s", filename);   // Extract filename from command
            printf("\nClient requested file: %s\n", filename);
            fprintf(log_file, "(Client requested file: %s)\n", filename);
            
            if (FAIL == file_get(client_socket, filename))
            {
                fprintf(stderr, "\nFailed to send file: %s\n", filename);
                memset(buffer, RESET, BUFFER_SIZE);
                continue;
            }
            
            continue;
        }

        // Check if client wants to see contents of server-repo
        if (0 == strncmp(buffer, "file_ls", sizeof("file_ls")))
        {
            printf("\n(Client wants to see server repo)\n");
            fprintf(log_file, "\nClient invoked file_ls \n");
            //file_ls(client_socket);
        
            // Error handling
            if (FAIL == file_ls(client_socket))
            {
                fprintf(stderr, "\nError executing file_ls. Continuing server operation.\n");
                fprintf(log_file, "\nError executing file_ls\n");
                fflush(log_file);
                continue;
            }
            printf("\nAwaiting response from client...\n");
            continue;
        }   

        // Server-side activity
        // Get server-side response 
        printf("\nEnter response to client (or type 'exit' to quit): ");
        memset(response, RESET, BUFFER_SIZE);
        if (NULL == fgets(response, BUFFER_SIZE, stdin))                // fgets returns NULL at EOF or error
        {
            fprintf(stderr, "Error reading input. Please try again.\n");
            continue;                                                   // Skip sending a response and prompt again
        }

        response[strcspn(response, "\n")] = '\0';                       // Remove newline and make data a string

        // Check if server wants to disconnect (typing exit)
        if (0 == strncmp(response, exit_cmd, strlen(exit_cmd)))
        {
            printf("\nServer exiting...\n\n");
            send(client_socket, response, strlen(response), 0);
            break;
        }

        // Send response to client
        send(client_socket, response, strlen(response), 0);
        fprintf(log_file, "Server: %s\n", response);                    // Log server response
        printf("\nAwaiting response from client...\n");
    }

    fprintf(log_file, "\n<End of communication>\n");
}