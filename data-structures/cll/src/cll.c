#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "cll.h"

/** All functions and methods for Circular Linked List */

Node* createNode(void* data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) 
    {
        fprintf(stderr, "Failed to allocate memory for new node");
        return NULL;
    }

    newNode->data = data;
    newNode->next = newNode; // Points to make it circular
    return newNode;
}

void insertAtEnd(Node** tail, void* data)
{
    Node* newNode = createNode(data);   // Create a new node

    if (*tail == NULL)                  // If this is the first node...
    { 
        *tail = newNode;               
    }
    else
    {
        newNode->next = (*tail)->next; // Point newNode to the head
        (*tail)->next = newNode;       // Update the old tail's next
        *tail = newNode;               // Update the tail to the new node
    }
}

void deleteNode(Node** tail, void* data, bool (*compare)(void*, void*))
{
    if (*tail == NULL)
    {
        printf("List is empty. Cannot delete.");
        return;
    }

    Node* current = (*tail)->next; // Start from the head
    Node* prev = *tail;

    do
    {
        if (1 == compare(current->data, data)) 
        { 
            if (current == current->next)
            { 
                *tail = NULL;
            }
            else
            {
                prev->next = current->next;
                if (current == *tail) 
                {
                    *tail = prev; // Update tail if we're deleting the tail
                }
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    } while (current != (*tail)->next);

    printf("Data not found in the list.\n");
}

void traverse(Node* tail, void (*printData)(void*))
{
    if (NULL == tail) 
    {
        printf("List is empty.\n");
        return;
    }

    Node* current = tail->next; // Start from the head
    do
    {
        printData(current->data);
        printf(" -> ");
        current = current->next;
    } while (current != tail->next);

    printf("(back to head)\n");
}

bool compareIntData(void* a, void* b) 
{
    return (*(int*)a == *(int*)b);
}

void printIntData(void* data)
{
    printf("%d", *(int*)data);
}