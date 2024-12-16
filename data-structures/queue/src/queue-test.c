#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue-methods.h"

int main() 
{
    PriorityQueueNode* pq = NULL;           // Initialize an empty priority queue 'pq'

    printf("Enqueuing elements into the priority queue:\n");
    // Data to be placed into nodes 
    int data1 = 10;
    int data2 = 20;
    int data3 = 30;
    int data4 = 40;

    // Enqueue the data into nodes within the queue (with priority)
    enqueue(&pq, &data1, 2);
    enqueue(&pq, &data2, 1);
    enqueue(&pq, &data3, 3);
    enqueue(&pq, &data4, 0);

    // Show the queue
    displayQueue(pq, printIntData);

    printf("\nDequeuing elements from the priority queue:\n");
    while (NULL != pq) 
    {
        int* data = (int*)dequeue(&pq);
        printf("Dequeued: %d\n", *data);
    }

    return 0;
}
