/**
 * @file bst-test.c
 * @author David Chung (david.chung1719@outlook.com)
 * @brief 
 * @version 1
 * @date 13Feb25
 * 
 * @brief Simple test to ensure the binary search table
 * functions as designed. 
 * 
 * Tests all functions found in file "bst.c/h"
 * 
 */

#include "../include/bst.h"

#define     ARRAY_VAL   {50, 30, 20, 40, 70, 60, 80}
#define     MAX_SIZE    7
#define     SEARCH_VAL  40
#define     DELETE_VAL  50
#define     PASS    0 
#define     FAIL    (-1)

int
main(void) 
{
    TreeNode_t* root = NULL;
    TreeNode_t* result = NULL;
    int index = 0;
    int key = 0;
    int values[MAX_SIZE] = ARRAY_VAL;

    // Insert values into the BST
    for (index = PASS; index < MAX_SIZE; index++) 
    {
        root = insert(root, &values[index], compare_int);
    }

    // In-order traversal
    printf("In-order traversal of the BST:\n");
    io_traverse(root, print_int);
    printf("\n");

    // Search for a value
    key = SEARCH_VAL;
    result = search(root, &key, compare_int);

    if (NULL != result) 
    {
        printf("Value %d found in the BST.\n", key);
    } 
    else 
    {
        printf("Value %d not found in the BST.\n", key);
    }

    // Delete a value
    key = DELETE_VAL;
    root = delete_node(root, &key, compare_int);
    printf("In-order traversal after deleting %d:\n", key);
    io_traverse(root, print_int);
    printf("\n");
    goto cleanup;

    cleanup:
        printf("Cleaning up...\n");
        free_tree(root);
        goto exit_pass;

    exit_pass:
        printf("Exited successfully\n");
        return PASS;
}

/*******************  END OF FILE *******************************/