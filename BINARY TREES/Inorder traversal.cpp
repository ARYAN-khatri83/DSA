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
    void inorder(TreeNode* node, vector<int>& inor) {
        if(node == NULL) return;
        inorder(node->left, inor);
        inor.push_back(node->val);
        inorder(node->right, inor);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inor;
        inorder(root, inor);
        return inor;
    }
};
