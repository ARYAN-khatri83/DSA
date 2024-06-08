Recursive sol
class Solution {
public:
    // Recursive function to solve the knapsack problem
    int knapsackRecursive(vector<int>& weights, vector<int>& values, int W, int n) {
        // Base case: no items left or no remaining capacity in the knapsack
        if (n == 0 || W == 0) return 0;

        // If the weight of the nth item is more than the knapsack capacity W, this item cannot be included
        if (weights[n-1] > W) return knapsackRecursive(weights, values, W, n-1);

        // Return the maximum of two cases:
        // 1. nth item included
        // 2. nth item not included
        return max(values[n-1] + knapsackRecursive(weights, values, W - weights[n-1], n-1),
                   knapsackRecursive(weights, values, W, n-1));
    }

    // Function to start the recursive knapsack solution
    int knapsack(vector<int>& weights, vector<int>& values, int W) {
        int n = weights.size();
        return knapsackRecursive(weights, values, W, n);
    }
};


Memoization
class Solution {
public:
    // Recursive function with memoization to solve the knapsack problem
    int knapsackMemoization(vector<int>& weights, vector<int>& values, int W, int n, vector<vector<int>>& memo) {
        // Base case: no items left or no remaining capacity in the knapsack
        if (n == 0 || W == 0) return 0;

        // If the result is already calculated, return it
        if (memo[n][W] != -1) return memo[n][W];

        // If the weight of the nth item is more than the knapsack capacity W, this item cannot be included
        if (weights[n-1] > W) return memo[n][W] = knapsackMemoization(weights, values, W, n-1, memo);

        // Store the result in the memo array and return the maximum of two cases:
        // 1. nth item included
        // 2. nth item not included
        return memo[n][W] = max(values[n-1] + knapsackMemoization(weights, values, W - weights[n-1], n-1, memo),
                                knapsackMemoization(weights, values, W, n-1, memo));
    }

    // Function to start the memoized knapsack solution
    int knapsack(vector<int>& weights, vector<int>& values, int W) {
        int n = weights.size();
        vector<vector<int>> memo(n + 1, vector<int>(W + 1, -1)); // Initialize memo array with -1
        return knapsackMemoization(weights, values, W, n, memo);
    }
};

Tabulation
class Solution {
public:
    // Function to solve the knapsack problem using tabulation (bottom-up DP)
    int knapsack(vector<int>& weights, vector<int>& values, int W) {
        int n = weights.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0)); // Initialize DP table with 0

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= W; w++) {
                if (weights[i-1] <= w) {
                    // Item can be included, take the maximum of including or excluding the item
                    dp[i][w] = max(dp[i-1][w], dp[i-1][w - weights[i-1]] + values[i-1]);
                } else {
                    // Item cannot be included
                    dp[i][w] = dp[i-1][w];
                }
            }
        }
        return dp[n][W]; // The answer is in dp[n][W]
    }
};


Space optimisation
class Solution {
public:
    // Function to solve the knapsack problem using space optimization with one row
    int knapsack(vector<int>& weights, vector<int>& values, int W) {
        int n = weights.size();
        vector<int> dp(W + 1, 0); // Initialize DP array with 0

        // Fill the DP array
        for (int i = 0; i < n; i++) {
            // Traverse the DP array from right to left
            for (int w = W; w >= weights[i]; w--) {
                // Update the DP array with the maximum value
                dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
            }
        }
        return dp[W]; // The answer is in dp[W]
    }
};


