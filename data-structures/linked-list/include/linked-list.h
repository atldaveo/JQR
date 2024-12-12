#ifndef LINKED_LIST_H
#define LINKED_LIST_H   

/** All functions and operations are assuming a Singly Linked List */
/**< Define the node structure of a linked list */
typedef struct Node 
{
/**< Pointer to location of data */
/**< void* allows acceptance of all datatypes */
    void* data;

/**< Pointer to next node */                   
    struct Node* next;

} Node;                                                     // Declare variable 'struct Node Node' globally

/** @brief Create and initialize a new Node
 * Assuming global declaration of node "Node".
 * 
 * @param data Void pointer to data to be stored in newNode.   
 * 
 * @return Node* Returns a pointer to a Node structure
 */
Node* createNode(void* data);

/** @brief Insert a node to a specific point within the linked list
 * 
 * @param head (Node) Pointer to next Node (or NULL)
 * @param index Where exactly you want the node to be inserted
 * @param data (Void) pointer to location of data to be sent to node  
 */
void insertNode(Node** head, int index, void* data);

/** @brief Add a node to the bottom of the linked list.
 * This node will link to the top of the list - making it circular
 * 
 * @param head (Node) Pointer to first node in the list
 * @param data (Void) pointer to location of data to be sent to node  
 */
void addNodeBottom(Node** head, void* data);

/** @brief Add a node to the head (top) of the linked list 
 * 
 * @param head Top of the list
 * @param data Data stored in the node
 */
void addNodeTop(Node** head, void* data);

/** @brief Delete a node by index */
void deleteNode(Node** head, int index);

/** @brief Modify data at a specific index */
void modifyNode(Node* head, int index, void* newData);

/************** MAIN FUNCTION HELPERS ******************************/

/** @brief Traverse and print each node's data */
void traverse(Node* head);

/** @brief Print the data with the node number (index) */
void printNodeDataWithIndex(Node* node, int index);

/** @brief Function to print the list (assume data are integers) */
void printList(Node* head);

#endif