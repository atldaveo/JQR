#ifndef CLL_H
#define CLL_H

#include <stdbool.h>

/**< Define the node structure of a linked list */
typedef struct Node {
    void* data;              // Pointer to data of any type
    struct Node* next;       // Pointer to the next node
} Node;

/**
 * @brief Create a Node object
 * 
 * @param data Data to be placed into a node
 * @return Node* Pointer to new node
 */
Node* createNode(void* data);

/**
 * @brief Insert a new node at the end of the list
 * 
 * @param tail Pointer to the pointer used to modify the tail pointer 
 * @param data Data to be placed into new node
 */
void insertAtEnd(Node** tail, void* data);

/**
 * @brief Deletes a selected node
 * 
 * @param tail Pointer to the pointer used to modify the tail pointer 
 * @param data Data to be placed into new node
 * @param compare Function pointer to a comparison function (between data)
 */
void deleteNode(Node** tail, void* data, bool (*compare)(void*, void*));

/**
 * @brief Traverse through circular linked list and stops at the tail (inclusive).
 * Prints node information during the traversal. 
 * 
 * @param tail Pointer to the tail node of list. End point
 * @param printData Functrion pointer to a print function for the data in node
 */
void traverse(Node* tail, void (*printData)(void*));

/**
 * @brief Compares (int) data 
 * 
 * @param a Data
 * @param b Other data
 * @return true If the data is the same
 * @return false If the data is different
 */
bool compareIntData(void* a, void* b);

/**
 * @brief Print function that prints the (int) data
 * 
 * @param data Data in the node
 */
void printIntData(void* data);

#endif