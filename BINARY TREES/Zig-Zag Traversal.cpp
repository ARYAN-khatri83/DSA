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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        
        vector<vector<int>> res;
        
        queue<TreeNode*> qu;
        qu.push(root);

        bool rightToLeft = false;
        
        while (!qu.empty()) {
            vector<int> curLevel;

            int sz = qu.size();
            for (int i = 0; i < sz; ++i) {
                auto node = qu.front();
                qu.pop();
                
                curLevel.push_back(node->val);
                
                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
            }

            if (rightToLeft)
                reverse(curLevel.begin(), curLevel.end());
            
            rightToLeft = !rightToLeft;

            res.push_back(curLevel);
        }

        return res;
    }
};

// OR 

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // If the root is null, return an empty vector
        if (!root)
            return {};
        
        vector<vector<int>> res; // This will store the final zigzag level order traversal result
        
        queue<TreeNode*> qu; // Queue to help with level order traversal
        qu.push(root); // Start with the root node

        bool rightToLeft = false; // Flag to determine the direction of zigzag
        
        while (!qu.empty()) { // Continue until there are no more nodes to process
            vector<int> curLevel; // Vector to store the current level's node values

            int sz = qu.size(); // Number of nodes at the current level
            for (int i = 0; i < sz; ++i) {
                auto node = qu.front(); // Get the front node from the queue
                qu.pop(); // Remove the front node from the queue
                
                curLevel.push_back(node->val); // Add the node's value to the current level vector
                
                // Add the node's children to the queue for the next level
                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
            }

            // If the current direction is right-to-left, reverse the current level's vector
            if (rightToLeft)
                reverse(curLevel.begin(), curLevel.end());
            
            // Toggle the direction for the next level
            rightToLeft = !rightToLeft;

            // Add the current level's vector to the result
            res.push_back(curLevel);
        }

        // Return the zigzag level order traversal result
        return res;
    }
};
