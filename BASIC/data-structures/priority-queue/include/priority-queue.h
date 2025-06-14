/**
 * @file priority-queue.h
 * @author David Chung (david.t.chung2.mil@army.mil)
 * @brief Prototypes and describes the functions in associated helper file priority-queue.c 
 * @version 3 (10APR25)
 * @date 10DEC24
 *  
 * NOTE: Lower priority number means higher priority (eg. 1 is a higher priority than 2)
 * 
*/

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/** @brief Define the structure for a priority queue node
 * 
 */
typedef struct PriorityQueueNode 
{
    void* p_data;     // Pointer to p_data of any type
    int priority;   // Priority of the node (lower number -> higher priority)
    struct PriorityQueueNode* next;
} PriorityQueueNode;

/** @brief Create a new priority queue node
 * 
 * @param p_data 
 * @param priority 
 * @return PriorityQueueNode* 
 */
PriorityQueueNode*
create_node(void* p_data, int priority);

/** @brief Insert a node into the priority queue
 * 
 * @param pp_head 
 * @param p_data 
 * @param priority 
 */
void
enqueue(PriorityQueueNode** pp_head, void* p_data, int priority);

/** @brief Remove and return the highest-priority node from the queue
 * 
 * @param pp_head 
 * @return void* 
 */
void*
dequeue(PriorityQueueNode** pp_head);

/** @brief Peek at the highest-priority node without removing it
 * 
 * @param pp_head 
 * @return void* 
 */
void*
peek(PriorityQueueNode* pp_head);

/** @brief Check if the priority queue is empty
 * 
 * @param pp_head 
 * @return true 
 * @return false 
 */
bool
is_empty(PriorityQueueNode* pp_head);

/** @brief Display the priority queue
 * 
 * @param pp_head 
 * @param printData 
 */
void
display_queue(PriorityQueueNode* head, void (*printData)(void*));

/** @brief Helper function to print integer p_data
 * 
 * @param p_data 
 */
void
print_int_data(void* p_data);

#endif

/*******************  END OF FILE *******************************/