/**
 * @file pq-test.c
 * @author David Chung 
 * @brief 
 * @version 1 (10APR25)
 * @date 13Feb25
 * 
 * @brief Basic test to ensure functionality of priority queue
 * as written in "priority-queue.c"
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/priority-queue.h"

#define DATA1   10
#define DATA2   20
#define DATA3   30
#define DATA4   40

#define HIGH    1
#define MED     2
#define LOW     3

#define TRUE    0

// Priority Queue Testing
int main(void)
{
    PriorityQueueNode* pq = NULL;   // Empty queue

    int data1 = DATA1;
    int data2 = DATA2;
    int data3 = DATA3;
    int data4 = DATA4;

    printf("Enqueuing elements into the priority queue:\n");
    enqueue(&pq, &data1, HIGH);
    enqueue(&pq, &data2, HIGH);
    enqueue(&pq, &data3, MED);
    enqueue(&pq, &data4, LOW);
    display_queue(pq, print_int_data);

    printf("\nDequeueing a single node...\n");
    dequeue(&pq);
    printf("Update:\n");
    display_queue(pq, print_int_data);

    printf("\nDequeuing elements from the priority queue:\n");
    while (!is_empty(pq))
    {
        int* p_data = (int*)dequeue(&pq);
        printf("Dequeued: %d\n", *p_data);
    }

    return 0;
}

/*******************  END OF FILE *******************************/