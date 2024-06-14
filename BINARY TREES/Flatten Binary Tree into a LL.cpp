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
    TreeNode* prev = nullptr; // Keep track of the previous node in the flattened list

    void flatten(TreeNode* root) {
        if (root == nullptr) return; // If the current node is null, return

        flatten(root->right); // Recursively flatten the right subtree
        flatten(root->left); // Recursively flatten the left subtree

        // Set the current node's left to null and right to the previous node
        root->left = nullptr;
        root->right = prev;
        prev = root; // Update the previous node to the current node
    }
};
