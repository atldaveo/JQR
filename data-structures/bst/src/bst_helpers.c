#include <stdio.h>
#include <stdlib.h>
#include "bst_helpers.h"

// Function to create a new tree node
TreeNode* createNode(void* data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
TreeNode* insert(TreeNode* root, void* data, int (*compare)(void*, void*)) {
    if (root == NULL) {
        return createNode(data);
    }

    if (compare(data, root->data) < 0) {
        root->left = insert(root->left, data, compare);
    } else if (compare(data, root->data) > 0) {
        root->right = insert(root->right, data, compare);
    }

    return root;
}

// Function to find the minimum value node in the BST
TreeNode* findMin(TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
TreeNode* deleteNode(TreeNode* root, void* data, int (*compare)(void*, void*)) {
    if (root == NULL) {
        return root;
    }

    if (compare(data, root->data) < 0) {
        root->left = deleteNode(root->left, data, compare);
    } else if (compare(data, root->data) > 0) {
        root->right = deleteNode(root->right, data, compare);
    } else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data, compare);
    }

    return root;
}

// Function to search for a value in the BST
TreeNode* search(TreeNode* root, void* data, int (*compare)(void*, void*)) {
    if (root == NULL || compare(data, root->data) == 0) {
        return root;
    }

    if (compare(data, root->data) < 0) {
        return search(root->left, data, compare);
    }

    return search(root->right, data, compare);
}

// Function to traverse the BST in-order
void inOrderTraversal(TreeNode* root, void (*printData)(void*)) {
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left, printData);
    printData(root->data);
    printf(" ");
    inOrderTraversal(root->right, printData);
}

/********************** Main Functions Helpers ******************************/

// Comparison function for integers
int compareInt(void* a, void* b) 
{
    return (*(int*)a - *(int*)b);
}

// Function to print integer data
void printInt(void* data)
{
    printf("%d", *(int*)data);
}