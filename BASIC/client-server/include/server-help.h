/**
 * @file server-help.h
 * @author David Chung
 * @brief A server-side function declarations. 
 * 
 * @version 1 (31JAN25)
 * @date 11JAN25
 *
 */

#ifndef SERVER_HELP_H
#define SERVER_HELP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>

#define PORT 8080
#define BUFFER_SIZE 1024

/**
 * @brief Interrupt to exit program gracefully via "ctrl-c"
 * 
 * @param signum 
 */
void exit_signal(int signum);

/**
 * @brief configure and initialize server-side socket
 * 
 * @param server_fd 
 * @param address 
 * @return int 
 */
int initialize_server(int *server_fd, struct sockaddr_in *address);

/**
 * @brief accepts client-side socket
 * 
 * @param server_fd 
 * @param address 
 * @param client_socket 
 * @return int 
 */
int accept_client(int server_fd, struct sockaddr_in *address, int *client_socket);

/**
 * @brief handles client connection once accepted
 * 
 * @param client_socket 
 * @param log_file 
 */
void handle_client(int client_socket, FILE *log_file);

#endif