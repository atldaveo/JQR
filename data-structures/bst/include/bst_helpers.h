#ifndef BST_H
#define BST_H

/**
 * @brief Define a structure for BST
 * 
 */
typedef struct TreeNode {
    void* data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode; 

/**
 * @brief Create a Node object
 * 
 * @param data 
 * @return TreeNode* 
 */
TreeNode* createNode(void* data);

/**
 * @brief 
 * 
 * @param root 
 * @param data 
 * @param compare 
 * @return TreeNode* 
 */
TreeNode* insert(TreeNode* root, void* data, int (*compare)(void*, void*));

/**
 * @brief 
 * 
 * @param root 
 * @return TreeNode* 
 */
TreeNode* findMin(TreeNode* root);

/**
 * @brief 
 * 
 * @param root 
 * @param data 
 * @param compare 
 * @return TreeNode* 
 */
TreeNode* deleteNode(TreeNode* root, void* data, int (*compare)(void*, void*));

/**
 * @brief 
 * 
 * @param root 
 * @param data 
 * @param compare 
 * @return TreeNode* 
 */
TreeNode* search(TreeNode* root, void* data, int (*compare)(void*, void*));

/**
 * @brief 
 * 
 * @param root 
 * @param printData 
 */
void inOrderTraversal(TreeNode* root, void (*printData)(void*));

/**
 * @brief Comparison function for integers
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int compareInt(void* a, void* b);

/**
 * @brief 
 * 
 * @param data 
 */
void printInt(void* data);

#endif