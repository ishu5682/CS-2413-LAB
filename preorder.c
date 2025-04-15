#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
 
    int val;
    struct TreeNode *left;
    struct TreeNode *right;


// Helper function to perform preorder traversal
void preorderHelper(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) return;
    
    result[(*returnSize)++] = root->val;             // Visit root
    preorderHelper(root->left, result, returnSize);  // Traverse left
    preorderHelper(root->right, result, returnSize); // Traverse right
}

// Main function to return preorder traversal
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = malloc(100 * sizeof(int));  // Allocate memory for result
    *returnSize = 0;
    preorderHelper(root, result, returnSize);
    return result;
}

