class Solution {
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Initialize a visited array to keep track of visited nodes
        int vis[V] = {0};
        // Mark the starting node (node 0) as visited
        vis[0] = 1;
        // Create a queue for BFS and enqueue the starting node
        queue<int> q;
        q.push(0);
        // Vector to store the BFS traversal
        vector<int> bfs;
        
        // Loop until the queue is empty
        while(!q.empty()) {
            // Dequeue a node from the queue
            int node = q.front();
            q.pop();
            // Add the node to the BFS traversal result
            bfs.push_back(node);
            
            // Traverse all adjacent nodes of the dequeued node
            for(auto it: adj[node]) {
                // If the adjacent node has not been visited
                if(!vis[it]) {
                    // Mark it as visited
                    vis[it] = 1;
                    // Enqueue the adjacent node
                    q.push(it);
                }
            }
        }
        // Return the BFS traversal result
        return bfs;
    }
};


Initialization:
A vis array of size V is initialized to 0 to keep track of visited nodes.
The starting node (vertex 0) is marked as visited by setting vis[0] to 1.
A queue q is initialized and the starting node (0) is pushed onto the queue.
A vector bfs is created to store the BFS traversal result.

BFS Loop:
The loop continues as long as there are nodes in the queue.
The front node is dequeued from the queue and added to the bfs vector.
All adjacent nodes of the dequeued node are iterated over.
If an adjacent node has not been visited, it is marked as visited and enqueued.

Return Result:
After the loop ends (i.e., when the queue is empty), the bfs vector, which contains the BFS traversal, is returned.
