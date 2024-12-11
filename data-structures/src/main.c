#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

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

/** @brief Insert a node at a specific point within the linked list
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

/** @brief  Delete a node by index */
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

/************************************************************************/

/** @brief Traverse and print each node's data */
void traverse(Node* head) 
{
    Node* current = head;
    int nodeNumber = 0;
    while (current != NULL) 
    {
        printf("Node %d contains: %d\n", nodeNumber, *(int*)current->data);
        current = current->next;
        nodeNumber++;
    }
}

/** @brief Print the data with the node number (index) */
void printNodeDataWithIndex(Node* node, int index) 
{
    printf("Node %d contains: %d\n", index, *(int*)node->data);
}

/** @brief Function to print the list (assume data are integers) */
void printList(Node* head) 
{
    Node* current = head;
    int index = 0;
    while (current != NULL) {
        printf("Node %d contains: %d\n", index++, *(int*)current->data);  // Dereference data as int
        current = current->next;  // Move to the next node
    }
}

/************************************************************************/

// Linked List functions validation
int main() {
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
    modifyNode(head, 2, &data4);   // Change value of Node2 from 30 to 50

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