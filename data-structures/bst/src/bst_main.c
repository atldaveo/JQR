#include <stdio.h>
#include <stdlib.h>
#include "bst_helpers.h"


// Main function to test the binary search tree
int main()
{
    TreeNode* root = NULL;

    int data1 = 50;
    int data2 = 30; 
    int data3 = 70; 
    int data4 = 20; 
    int data5 = 40; 
    int data6 = 60; 
    int data7 = 80;

    // Insert elements into the BST
    root = insert(root, &data1, compareInt);
    root = insert(root, &data2, compareInt);
    root = insert(root, &data3, compareInt);
    root = insert(root, &data4, compareInt);
    root = insert(root, &data5, compareInt);
    root = insert(root, &data6, compareInt);
    root = insert(root, &data7, compareInt);

    printf("In-order traversal of the BST: \n");
    inOrderTraversal(root, printInt);
    printf("\n");

    // Delete a node from the BST
    printf("Deleting 20 from the BST\n");
    root = deleteNode(root, &data4, compareInt);
    printf("In-order traversal after deletion: \n");
    inOrderTraversal(root, printInt);
    printf("\n");

    // Search for a node in the BST
    printf("Searching for 40 in the BST: \n");
    TreeNode* searchResult = search(root, &data5, compareInt);
    if (NULL != searchResult)
    {
        printf("Found: %d\n", *(int*)searchResult->data);
    } 
    else 
    {
        printf("Not found\n");
    }

    return 0;
}