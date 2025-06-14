/**
 * @file cll.c
 * @author David Chung 
 * @brief Function definitions for circular linked list 
 * @version 3 (12APR25)
 * @date 10DEC24
 *  
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/cll.h"

Node*
create_node(void* p_data) 
{
    Node* new_node = NULL;
    
    new_node = (Node*)malloc(sizeof(Node));

    if (NULL == new_node) 
    {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }

    new_node->p_data = p_data;
    new_node->next = new_node; // Points to itself for circularity
    
    return new_node;
}

void
insert_at_end(Node** pp_tail, void* p_data) 
{
    Node* new_node = create_node(p_data);

    if (NULL == *pp_tail) 
    { // If the list is empty
        *pp_tail = new_node;
    } 
    else 
    {
        new_node->next = (*pp_tail)->next; // Point new_node to the head
        (*pp_tail)->next = new_node;       // Update the old pp_tail's next
        *pp_tail = new_node;               // Update the pp_tail to the new node
    }
}

void
delete_node(Node** pp_tail, void* p_data, bool (*compare)(void*, void*)) 
{
    if (NULL == *pp_tail) 
    {
        printf("List is empty. Cannot delete.");
        return;
    }

    Node* current = (*pp_tail)->next; // Start from the head
    Node* prev = *pp_tail;

    do 
    {
        if (compare(current->p_data, p_data)) 
        { 
            // Match found
            if (current == current->next) 
            { // Single node case
                *pp_tail = NULL;
            } 
            else 
            {
                prev->next = current->next;
                if (current == *pp_tail) 
                {
                    *pp_tail = prev; // Update pp_tail if we're deleting the pp_tail
                }
            }

            free(current);

            return;
        }
        prev = current;
        current = current->next;
    } 

    while (current != (*pp_tail)->next);

    printf("Data not found in the list.\n");
}

void
traverse(Node* pp_tail, void (*print_data)(void*)) 
{
    if (NULL == pp_tail) 
    {
        printf("List is empty.\n");
        return;
    }

    Node* current = pp_tail->next; // Start from the head
    
    do 
    {
        print_data(current->p_data);
        printf(" -> ");
        current = current->next;
    } 
    while (current != pp_tail->next);

    printf("(back to head)\n");
}

bool
compare_int_data(void* first_datum, void* second_datum) 
{
    return (*(int*)first_datum == *(int*)second_datum);
}

void
print_int_data(void* p_data) 
{
    printf("%d", *(int*)p_data);
}

/*******************  END OF FILE *******************************/