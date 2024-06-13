/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // Main function to build the tree from inorder and postorder traversal arrays
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size(); // Get the size of the inorder array
        int Idx = n - 1; // Initialize index to track the root position in postorder array
        return helper(inorder, postorder, Idx, 0, n - 1); // Call helper to start tree construction
    }
    
    // Helper function to construct the tree
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int& Idx, int left, int right) {
        // Base case: if left index is greater than right, the subtree is invalid
        if (left > right) return NULL;

        // Find the root in the inorder array using the current root from postorder
        int pivot = left; 
        while(inorder[pivot] != postorder[Idx]) pivot++;

        // Create the root node with the value from inorder[pivot]
        TreeNode* newNode = new TreeNode(inorder[pivot]);

        // Decrement Idx to move to the next root in postorder array
        Idx--;

        // Recursively build the right subtree
        // Elements from pivot+1 to right in the inorder array form the right subtree
        newNode->right = helper(inorder, postorder, Idx, pivot + 1, right);

        // Recursively build the left subtree
        // Elements from left to pivot-1 in the inorder array form the left subtree
        newNode->left = helper(inorder, postorder, Idx, left, pivot - 1);

        // Return the newly created node
        return newNode;
    }
};
