#include <stdio.h>
#include <stdlib.h>

#include "cll.h"

int main()
{
    Node* tail = NULL;

    // Data to be placed into nodes
    int data1 = 10;
    int data2 = 20;
    int data3 = 30;
    int data4 = 40;

    // Insert elements
    insertAtEnd(&tail, &data1);
    insertAtEnd(&tail, &data2);
    insertAtEnd(&tail, &data3);
    insertAtEnd(&tail, &data4);

    printf("Circular Linked List after insertion:\n");
    traverse(tail, printIntData);

    // Delete an element
    printf("\nDeleting 20 from the list:\n");
    deleteNode(&tail, &data2, compareIntData);
    traverse(tail, printIntData);

    // Delete another element
    printf("\nDeleting 40 from the list:\n");
    deleteNode(&tail, &data4, compareIntData);
    traverse(tail, printIntData);

    return 0;
}