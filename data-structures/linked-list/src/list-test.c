#include <stdio.h>
#include <stdlib.h>

#include "linked-list.h"

// Methods validation
int main() 
{    
    Node* head = NULL;  // Start with an empty list

    // Example data (to be stored in nodes)
    int data1 = 10;
    int data2 = 20; 
    int data3 = 30;
    int data4 = 50;

    // Manipulate the list entries using new functions
    addNodeTop(&head, &data1);      // Add 10 at the head (Node0)
    addNodeTop(&head, &data2);      // Add 20 at the head (Node1)
    addNodeTop(&head, &data3);      // Add 30 at the head (Node2)
    //deleteNode(&head, 1);         // Delete node containing 20
    modifyNode(head, 2, &data4);    // Change data of Node2 from 30 to 50

    // Print the linked list by index
    // Order should be Node2 (Head), Node1, Node0
    traverse(head);         

    // Free allocated memory (important for avoiding memory leaks)
    Node* current = head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}