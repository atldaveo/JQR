/**
 * @file bst.c
 * @author David Chung (david.t.chung2.mil@army.mil)
 * @brief Function definitions for binary search table 
 * @version 3 (11APR25)
 * @date 10DEC24
 *  
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/bst.h"

#define     PASS    0 
#define     FAIL    (-1)

void
free_tree(TreeNode_t* root)
{
    if (NULL == root)
    {   
        return;
    }

    free_tree(root->node_left);
    free_tree(root->node_right);
    free(root);
}

TreeNode_t*
create_node(void* p_data) 
{
    TreeNode_t* new_node = NULL;
    new_node = (TreeNode_t*)malloc(sizeof(TreeNode_t)); 
    
    if (NULL == new_node) 
    {
        printf("Failed to allocate memory for new node\n");
        exit(EXIT_FAILURE);
    }

    new_node->p_data = p_data;
    new_node->node_left = NULL;
    new_node->node_right = NULL;
    
    return new_node;
}

TreeNode_t*
insert(TreeNode_t* p_root, void* p_data, int (*compare)(void*, void*)) 
{
    if (NULL == p_root) 
    {
        return create_node(p_data);
    }

    if (PASS > compare(p_data, p_root->p_data)) 
    {
        p_root->node_left = insert(p_root->node_left, p_data, compare);
    } 

    if (PASS < compare(p_data, p_root->p_data)) 
    {
        p_root->node_right = insert(p_root->node_right, p_data, compare);
    }

    return p_root;
}

TreeNode_t*
find_min(TreeNode_t* p_root) 
{
    while (NULL != p_root->node_left) 
    {
        p_root = p_root->node_left;
    }

    return p_root;
}

TreeNode_t*
delete_node(TreeNode_t* p_root, void* p_data, int (*compare)(void*, void*))
{
    TreeNode_t* temp = NULL;

    if (NULL == p_root) 
    {
        return p_root;
    }

    if (PASS > compare(p_data, p_root->p_data)) 
    {
        p_root->node_left = delete_node(p_root->node_left, p_data, compare);
    }

    if (PASS < compare(p_data, p_root->p_data)) 
    {
        p_root->node_right = delete_node(p_root->node_right, p_data, compare);
    }
    
    if (NULL == p_root->node_left) 
    {
        temp = p_root->node_right;
        free(p_root);
        return temp;
    }

    if (NULL == p_root->node_right) 
    {
        temp = p_root->node_left;
        free(p_root);
        return temp;
    }

    temp = find_min(p_root->node_right);
    p_root->p_data = temp->p_data;
    p_root->node_right = delete_node(p_root->node_right, temp->p_data, compare);

    return p_root;
}

TreeNode_t*
search(TreeNode_t* p_root, void* p_data, int (*compare)(void*, void*)) 
{
    if ((NULL == p_root) || (PASS == compare(p_data, p_root->p_data))) 
    {
        return p_root;
    }

    if (PASS > compare(p_data, p_root->p_data)) 
    {
        return search(p_root->node_left, p_data, compare);
    }

    return search(p_root->node_right, p_data, compare);
}

void
io_traverse(TreeNode_t* p_root, void (*print_data)(void*)) 
{
    if (NULL == p_root) 
    {
        return;
    }

    io_traverse(p_root->node_left, print_data);
    print_data(p_root->p_data);
    printf(" ");
    io_traverse(p_root->node_right, print_data);
}

int
compare_int(void* p_first_int, void* p_second_int) 
{
    return (*(int*)p_first_int - *(int*)p_second_int);
}

void
print_int(void* p_data) 
{
    printf("%d", *(int*)p_data);
}

/*******************  END OF FILE *******************************/