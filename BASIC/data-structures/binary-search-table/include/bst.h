/**
 * @file bst.h
 * @author David Chung (david.t.chung2.mil@army.mil)
 * @brief Prototypes and describes the functions in associated helper file bst.c 
 * @version 2 (9APR25)
 * @date 10DEC24
 *  
*/
#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

/**< Define the structure of a binary search tree node */
typedef struct TreeNode_t 
{
    void* p_data;
    struct TreeNode_t* node_left;
    struct TreeNode_t* node_right;
} TreeNode_t;

/** @brief Create a new (tree) Node object
 * 
 * @param p_data (of any p_data type)
 * @return TreeNode_t* 
 */
TreeNode_t*
create_node(void* p_data);

/** @brief Function to insert a node into the BST
 * 
 * @param root 
 * @param p_data 
 * @param compare 
 * @return TreeNode_t* 
 */
TreeNode_t*
insert(TreeNode_t* root, void* p_data, int (*compare)(void*, void*));

/** @brief Function to find the minimum value node in the BST
 * 
 * @param root 
 * @return TreeNode_t* 
 */
TreeNode_t*
find_min(TreeNode_t* root);

/** @brief Function to delete a node from the BST
 * 
 * @param root 
 * @param p_data 
 * @param compare 
 * @return TreeNode_t* 
 */
TreeNode_t*
delete_node(TreeNode_t* root, void* p_data, int (*compare)(void*, void*));

/** @brief Function to search for a value in the BST
 * 
 * @param root 
 * @param p_data Data to be deleted
 * @param compare 
 * @return TreeNode_t* 
 */
TreeNode_t*
search(TreeNode_t* root, void* p_data, int (*compare)(void*, void*));

/** @brief Frees the memory allocated for the whole BST
 * 
 * @param root Existing search tree
 */
void
free_tree(TreeNode_t* root);

/** @brief Function to traverse the BST in-order
 * 
 * @param root 
 * @param printData 
 */
void
io_traverse(TreeNode_t* root, void (*printData)(void*));

/** @brief Comparison function for integers
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int
compare_int(void* a, void* b);

/** @brief Function to print integer p_data. Must explicitly cast and define 
 * print function because of the nature of void* p_data type 
 * @param p_data 
 */
void
print_int(void* p_data);

#endif

/*******************  END OF FILE *******************************/