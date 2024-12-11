#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

/** All functions and operations are assuming a Singly Linked List */

/**< @brief Define the node structure of a linked list */
typedef struct Node 
{
/**< Pointer to location of data */
/**< void* allows acceptance of all datatypes */
    void* data;

/**< Pointer to next node */                   
    struct Node* next;

} Node;                                                     // Declare variable 'struct Node Node' globally

/** @brief Create and initialize a new Node (object)
 * Assuming global declaration of node "Node".
 * 
 * @param data Void pointer to data to be stored in newNode.   
 * 
 * @return Node* Returns a pointer to a Node structure
 */
Node* createNode(void* data) 
{
/** Dynamically allocate memory for a new node.
 *  (Node*) Type-casting. 
 * 
 *  Since malloc() returns a generic pointer, we convert it into a node pointer 
 *  before assign to newNode via explicit declaration (Node*).
 */
    Node* newNode = (Node*)malloc(sizeof(Node));            // sizeof() ensures that the right amount of memory is allocated.
    newNode->data = data;                                   // Access value of member 'data' (void ptr) of newNode and assigns 'data'.  
    newNode->next = NULL;                                   // Sets value of member 'next' (node ptr) of 'newNode' and assigns 'NULL' (to indicate final node).
    return newNode;                                         // Return a (node) pointer to the new node
}

/** @brief Insert a node to a specific point within the linked list
 * 
 * @param head (Node) Pointer to next Node (or NULL)
 * @param index Where exactly you want the node to be inserted
 * @param data (Void) pointer to location of data to be sent to node  
 */
void insertNode(Node** head, int index, void* data) 
{
    Node* newNode = createNode(data);
    if (index == 0) 
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    for (int i = 0; temp != NULL && i < index - 1; i++) 
    {
        temp = temp->next;
    }
    if (temp == NULL) return;

    newNode->next = temp->next;
    temp->next = newNode;
}

/** @brief Add a node to the bottom of the linked list
 * 
 * @param head (Node) Pointer to first node in the list
 * @param data (Void) pointer to location of data to be sent to node  
 */
void addNodeBottom(Node** head, void* data) 
{
    /**< Create a new node */
    Node* newNode = createNode(data);                       // Create a new node using data pointer input
    
    /**< Check if the linked list has nodes */
    if (*head == NULL)                                      // If *head is NULL, no nodes exist in list...  
    {
        *head = newNode;                                    // Make new node the head of the list 
        return;                                             // Exit because new node is the first and only in list
    }

    /**< Traverse to end of the list (from the front) */
    Node* current = *head;                                  // Initialize (Node) pointer '*current' to start at head of the list
    while (current->next != NULL)                           // While the current node is pointing to another node...   
    {    
        current = current->next;                            // Iterate to next node
    }
    /**< Link last node to new node (new node points to last node - making it the rear-most node) */
    /**< Pointer 'current' should now be pointing to the last node in the list */
    current->next = newNode;                                // Update 'next' pointer to point to newNode  
}

/** @brief Add a node to the head (top) of the linked list 
 * 
 * @param head Top of the list
 * @param data Data stored in the node
 */
void addNodeTop(Node** head, void* data) 
{
    Node* newNode = createNode(data);   // Create the new node with the provided data
    newNode->next = *head;              // Point the new node to the current head of the list
    *head = newNode;                    // Update the head to point to the new node
}

/** @brief Delete a node by index */
void deleteNode(Node** head, int index) 
{
    if (*head == NULL)
    {
        return;
    }

    Node* temp = *head;

    if (index == 0) 
    {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < index - 1; i++) 
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) return;

    Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

/** @brief Modify data at a specific index */
void modifyNode(Node* head, int index, void* newData) 
{
    Node* temp = head;
    int i = 0;
    while (temp != NULL && i < index) 
    {
        temp = temp->next;
        i++;
    }
    if (temp != NULL) temp->data = newData;
}