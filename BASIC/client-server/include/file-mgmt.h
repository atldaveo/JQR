/**
 * @file file-mgmt.h
 * @author David Chung
 * @brief A server-side file mgmt function declarations. 
 * 
 * @version 1 (31JAN25)
 * @date 31JAN25
 *
 */

#ifndef FILE_MGMT_H
#define FILE_MGMT_H

/**
 * @brief transfer file from client to server
 * 
 * @param client_socket 
 * @param filename 
 */
int file_get(int client_socket, const char *filename);


/**
 * @brief Lists current files in the directory
 * 
 * @param takes socket info and lists items in the directoy 
 *  
 */
int file_ls(int client_socket);

#endif