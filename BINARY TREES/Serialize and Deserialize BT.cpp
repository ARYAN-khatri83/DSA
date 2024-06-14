class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return ""; // If the root is null, return an empty string

        string s;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();
            if (currNode == NULL) {
                s.append("#,"); // Use '#' to denote null nodes
            } else {
                s.append(to_string(currNode->val) + ','); // Append the value of the current node followed by a comma
                q.push(currNode->left); // Enqueue left child
                q.push(currNode->right); // Enqueue right child
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL; // If data is empty, return null

        stringstream s(data); // stringstream is used for breaking the string into tokens based on a delimiter
        string str; // To store individual tokens
        getline(s, str, ','); // Read the first token from the stream and store it in str. Tokens are separated by commas.

        TreeNode* root = new TreeNode(stoi(str)); // stoi converts the string token to an integer to create the root node
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ','); // Read the next token for the left child
            if (str == "#") {
                node->left = NULL; // If the token is "#", the left child is null
            } else {
                TreeNode* leftNode = new TreeNode(stoi(str)); // Convert the token to an integer and create the left child node
                node->left = leftNode;
                q.push(leftNode); // Enqueue the left child
            }

            getline(s, str, ','); // Read the next token for the right child
            if (str == "#") {
                node->right = NULL; // If the token is "#", the right child is null
            } else {
                TreeNode* rightNode = new TreeNode(stoi(str)); // Convert the token to an integer and create the right child node
                node->right = rightNode;
                q.push(rightNode); // Enqueue the right child
            }
        }
        return root;
    }
};


serialize Function:
This function converts the binary tree into a string.
A level-order traversal (BFS) is used to process each node.
If a node is NULL, a "#," is appended to the string to represent null.
Otherwise, the value of the node is appended followed by a comma.
This ensures that the structure of the tree is captured in the string.

deserialize Function:
This function converts the string back into a binary tree.
A stringstream is used to split the string by commas.
The first value is read to create the root node.
A queue is used to keep track of nodes whose children need to be assigned.
For each node, the next two values are read from the string to determine the left and right children.
If a value is "#", the corresponding child is NULL.
  
Otherwise, a new TreeNode is created, and the child is assigned and enqueued for further processing.

stringstream:
stringstream is a stream class to operate on strings.
It's used to break a string into tokens based on a delimiter. Here, it's used to parse the serialized string by commas.

getline:
getline reads characters from an input stream and stores them into a string.
The function reads characters until a delimiter is encountered (in this case, a comma).
getline(s, str, ',') reads from the stringstream s and stores the result in str until a comma is found.

stoi:
stoi converts a string to an integer.
It's used to convert the string tokens back into integers when reconstructing the tree nodes.
