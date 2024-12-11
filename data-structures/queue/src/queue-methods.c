#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue-methods.h"

PriorityQueueNode* createNode(void* data, int priority) 
{
    PriorityQueueNode* node = (PriorityQueueNode*)malloc(sizeof(PriorityQueueNode));
    node->data = data;
    node->priority = priority;
    node->next = NULL;
    return node;
}

void enqueue(PriorityQueueNode** head, void* data, int priority)
{
    PriorityQueueNode* newNode = createNode(data, priority);

    // If the queue is empty or the new node has higher priority than the head
    if ((NULL == *head) || ((*head)->priority > priority)) 
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse the queue to find the correct position
    PriorityQueueNode* current = *head;
    while ((current->next != NULL) && (current->next->priority <= priority)) {
        current = current->next;
    }

    // Insert the new node
    newNode->next = current->next;
    current->next = newNode;
}

void* dequeue(PriorityQueueNode** head) 
{
    if (NULL == *head) 
    {
        printf("Priority Queue is empty.\n");
        return NULL;                                // Indicate an empty queue
    }

    PriorityQueueNode* temp = *head;
    void* data = temp->data;
    *head = (*head)->next;                          // Update the head to the next node
    free(temp);                                     // Free the memory of the dequeued node
    return data;
}

void* peek(PriorityQueueNode* head) 
{
    if (NULL == head) 
    {
        printf("Priority Queue is empty.\n");
        return NULL;                    // Indicate an empty queue
    }
    return head->data;
}

void printIntData(void* data) 
{
    printf("%d", *(int*)data);
}

void displayQueue(PriorityQueueNode* head, void (*printData)(void*)) 
{
    if (NULL == head)                           // If the queue is empty
    {
        printf("Priority Queue is empty.\n");
        return;
    }

    PriorityQueueNode* current = head;          // New pointer to the head of the queue
    printf("Priority Queue: \n");
    while (NULL != current) 
    {
        printf("Priority: %d, Data: ", current->priority);
        printData(current->data);
        printf("\n");
        current = current->next;
    }
}
