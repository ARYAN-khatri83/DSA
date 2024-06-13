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
    // Main function to build the tree from preorder and inorder traversal arrays
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size(); // Get the size of the inorder array
        int Idx = 0; // Initialize index to track the root position in preorder array
        return helper(preorder, inorder, Idx, 0, n-1); // Call helper to start tree construction
    }
    
    // Helper function to construct the tree
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& Idx, int left, int right) {
        // Base case: if left index is greater than right, the subtree is invalid
        if (left > right) return NULL;

        // Find the root in the inorder array using the current root from preorder
        int pivot = left; 
        while(inorder[pivot] != preorder[Idx]) pivot++;

        // Increment Idx to move to the next root in preorder array
        Idx++;

        // Create the root node with the value from inorder[pivot]
        TreeNode* newNode = new TreeNode(inorder[pivot]);

        // Recursively build the left subtree
        // Elements from left to pivot-1 in the inorder array form the left subtree
        newNode->left = helper(preorder, inorder, Idx, left, pivot-1);

        // Recursively build the right subtree
        // Elements from pivot+1 to right in the inorder array form the right subtree
        newNode->right = helper(preorder, inorder, Idx, pivot+1, right);

        // Return the newly created node
        return newNode;
    }
};
