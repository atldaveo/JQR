/**
 * @file priority-queue.c
 * @author David Chung (david.t.chung2.mil@army.mil)
 * @brief Function definitions for priority queues 
 * @version 2 (13FEB25)
 * @date 10DEC24
 *  
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/priority-queue.h"

PriorityQueueNode*
create_node(void* p_data, int priority)
{
    PriorityQueueNode* node = (PriorityQueueNode*)malloc(sizeof(PriorityQueueNode));
    node->p_data = p_data;
    node->priority = priority;
    node->next = NULL;
    return node;
}

void
enqueue(PriorityQueueNode** pp_head, void* p_data, int priority)
{
    PriorityQueueNode* newNode = create_node(p_data, priority);

    // If the queue is empty or the new node has higher priority than the head
    if (NULL == *pp_head || (*pp_head)->priority > priority)
    {
        newNode->next = *pp_head;
        *pp_head = newNode;
        return;
    }

    // Traverse the queue to find the correct position
    PriorityQueueNode* current = *pp_head;
    while (current->next != NULL && current->next->priority <= priority)
    {
        current = current->next;
    }

    // Insert the new node
    newNode->next = current->next;
    current->next = newNode;
}

void*
dequeue(PriorityQueueNode** pp_head)
{
    if (NULL == *pp_head)
    {
        printf("Priority Queue is empty.\n");
        return NULL;  // Indicate an empty queue
    }

    PriorityQueueNode* temp = *pp_head;
    void* p_data = temp->p_data;
    *pp_head = (*pp_head)->next;  // Update the pp_head to the next node
    free(temp);             // Free the memory of the dequeued node
    return p_data;
}

void*
peek(PriorityQueueNode* pp_head)
{
    if (NULL == pp_head)
    {
        printf("Priority Queue is empty.\n");
        return NULL;  // Indicate an empty queue
    }
    return pp_head->p_data;
}

bool
is_empty(PriorityQueueNode* pp_head)
{
    return NULL == pp_head;
}

void
display_queue(PriorityQueueNode* pp_head, void (*printData)(void*))
{
    if (NULL == pp_head)
    {
        printf("Priority Queue is empty.\n");
        return;
    }

    PriorityQueueNode* current = pp_head;
    printf("Priority Queue: \n");
    while (NULL != current)
    {
        printf("Priority: %d, Data: ", current->priority);
        printData(current->p_data);
        printf("\n");
        current = current->next;
    }
}

void
print_int_data(void* p_data)
{
    printf("%d", *(int*)p_data);
}

/*******************  END OF FILE *******************************/