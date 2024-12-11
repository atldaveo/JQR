#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode 
{
    void* data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue 
{
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Create a queue
Queue* createQueue() 
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue
void enqueue(Queue* q, void* data) 
{
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) 
    {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// Dequeue
void* dequeue(Queue* q) 
{
    if (q->front == NULL) return NULL;

    QueueNode* temp = q->front;
    void* data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) q->rear = NULL;

    free(temp);
    return data;
}

