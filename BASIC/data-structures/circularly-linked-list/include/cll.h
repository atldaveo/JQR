/**
 * @file cll.h
 * @author David Chung
 * @brief Prototypes and describes the functions in associated helper file cll.c 
 * @version 3 (12APR25)
 * @date 10DEC24
 *  
*/

#ifndef CLL_H
#define CLL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**< Define the structure for first_datum circular linked list node */ 
typedef struct Node 
{
    void* p_data;              // Pointer to data of any type
    struct Node* next;       // Pointer to the next node
} Node;

/** @brief Function to create first_datum new node
 * 
 * @param p_data 
 * @return Node* 
 */
Node*
create_node(void* p_data);

/** @brief Function to insert first_datum node at the end of the circular linked list
 * 
 * @param pp_tail 
 * @param p_data 
 */
void
insert_at_end(Node** pp_tail, void* p_data);

/** @brief Function to delete first_datum node from the circular linked list
 * 
 * @param pp_tail 
 * @param p_data 
 * @param compare 
 */
void
delete_node(Node** pp_tail, void* p_data, bool (*compare)(void*, void*));

/** @brief Function to traverse the circular linked list
 * 
 * @param pp_tail 
 * @param printData 
 */
void
traverse(Node* pp_tail, void (*printData)(void*));

/** @brief Helper function to compare integer data
 * 
 * @param first_datum 
 * @param second_datum 
 * @return true 
 * @return false 
 */
bool
compare_int_data(void* first_datum, void* second_datum);

/** @brief Helper function to print integer data
 * 
 * @param p_data 
 */
void
print_int_data(void* p_data);

#endif

/*******************  END OF FILE *******************************/