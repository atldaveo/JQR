#ifndef QUEUE_METHODS_H
#define QUEUE_METHODS_H

/**
 * @brief Helper functions / methods for a priority queue
 * 
 */

/**< Define structure for priority queue node */
typedef struct PriorityQueueNode 
{
    void* data;     // Pointer to data of any type
    int priority;   // Priority of the node (lower number -> higher priority)
    struct PriorityQueueNode* next;
} PriorityQueueNode;

/** @brief Create a Priority queue node
 * 
 * @param data data to be held in node
 * @param priority priority level for node (lower number means higher priority)
 * @return PriorityQueueNode* Pointer to the newly made node
 */
PriorityQueueNode* createNode(void* data, int priority);

/** @brief Insert a node into the priority queue
 * 
 * @param head pointer to start node of the queue
 * @param data data to be associated with the node
 * @param priority priority level of the node
 */
void enqueue(PriorityQueueNode** head, void* data, int priority);

/** @brief Remove and return the highest-priority node from the queue
 * 
 * @param head pointer to start node of the queue
 * @return void* no return value
 */
void* dequeue(PriorityQueueNode** head);

/** @brief Peek at the highest-priority node without removing it
 * 
 * @param head pointer to starting node of queue
 * @return void* no return value
 */
void* peek(PriorityQueueNode* head);

/** @brief Prints the data as an integer (Test Helper)
 * 
 * @param data data from queue node
 */
void printIntData(void* data);

/**
 * @brief Print / view the queue
 * 
 * @param head pointer to the top node of the queue
 * @param printData pointer to a print function (to print the data)
 */
void displayQueue(PriorityQueueNode* head, void (*printData)(void*));

#endif