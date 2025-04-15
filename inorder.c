#include <stdio.h>
#include <stdlib.h>

// Helper function to perform inorder traversal
void inorderHelper(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) return;

    inorderHelper(root->left, result, returnSize);   // Traverse left
    result[(*returnSize)++] = root->val;             // Visit root
    inorderHelper(root->right, result, returnSize);  // Traverse right
}

// Main function to return inorder traversal
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = malloc(100 * sizeof(int));  // Allocate memory for result
    *returnSize = 0;
    inorderHelper(root, result, returnSize);
    return result;
}
