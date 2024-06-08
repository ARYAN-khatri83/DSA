// Recursice function

class Solution {
public:
    // Helper function for the recursive approach
    int f(int index, int Target, vector<int>& coins) {
        // Base case: If Target is 0, no coins are needed
        if (Target == 0) return 0;
        // Base case: If there are no coins left and Target is not zero, return a large value
        if (index < 0) return 1e9;
        // Base case: If only one type of coin is left
        if (index == 0) {
            if (Target % coins[0] == 0) return Target / coins[0];
            return 1e9;
        }

        // Option 1: Do not take the current coin
        int notTake = f(index - 1, Target, coins);
        // Option 2: Take the current coin if possible
        int take = INT_MAX;
        if (coins[index] <= Target) {
            take = 1 + f(index, Target - coins[index], coins);
        }

        // Return the minimum of taking or not taking the coin
        return min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = f(n - 1, amount, coins);
        // If the answer is greater than a large value, it means it's not possible to make the amount
        if (ans >= 1e9) return -1;
        return ans;
    }
};


// Memoization
class Solution {
public:
    // Helper function for the recursive approach
    int f(int index, int Target, vector<int>& coins, vector<vector<int>>& dp) {
        // Base case: If Target is 0, no coins are needed
        if (Target == 0) return 0;
        // Base case: If there are no coins left and Target is not zero, return a large value
        if (index < 0) return 1e9;
        // Base case: If only one type of coin is left
        if (index == 0) {
            if (Target % coins[0] == 0) return Target / coins[0];
            return 1e9;
        }
        // Check if the subproblem is already solved
        if (dp[index][Target] != -1) return dp[index][Target];

        // Option 1: Do not take the current coin
        int notTake = f(index - 1, Target, coins, dp);
        // Option 2: Take the current coin if possible
        int take = INT_MAX;
        if (coins[index] <= Target) {
            take = 1 + f(index, Target - coins[index], coins, dp);
        }

        // Store the result in dp array and return the minimum of taking or not taking the coin
        dp[index][Target] = min(take, notTake);
        return dp[index][Target];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(n - 1, amount, coins, dp);
        // If the answer is greater than a large value, it means it's not possible to make the amount
        if (ans >= 1e9) return -1;
        return ans;
    }
};


// Tabulation
class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        // Initialize the base case: If Target is 0, no coins are needed
        for (int Target = 0; Target <= amount; Target++) {
            if (Target % coins[0] == 0) dp[0][Target] = Target / coins[0];
            else dp[0][Target] = 1e9;  // This needs to be inside the loop
        }

        // Fill the rest of the dp table
        for (int index = 1; index < n; index++) {
            for (int Target = 0; Target <= amount; Target++) {
                // Option 1: Do not take the current coin
                int notTake = dp[index - 1][Target];
                // Option 2: Take the current coin if possible
                int take = INT_MAX;
                if (coins[index] <= Target) {
                    take = 1 + dp[index][Target - coins[index]];
                }

                // Store the result in dp array and return the minimum of taking or not taking the coin
                dp[index][Target] = min(take, notTake);
            }
        }

        // The answer is the minimum number of coins to make up the amount
        int ans = dp[n - 1][amount];
        return (ans >= 1e9) ? -1 : ans;
    }
};


// SPACE OPTIMIZATION
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);  // Two vectors for storing previous and current DP states

        // Initialize the base case: If Target is 0, no coins are needed
        for (int Target = 0; Target <= amount; Target++) {
            if (Target % coins[0] == 0) 
                prev[Target] = Target / coins[0];  // If Target is divisible by the first coin, use that many coins
            else 
                prev[Target] = 1e9;  // Otherwise, set to a large number (infinity equivalent)
        }

        // Fill the rest of the dp table
        for (int index = 1; index < n; index++) {
            for (int Target = 0; Target <= amount; Target++) {
                // Option 1: Do not take the current coin
                int notTake = prev[Target];  // Carry forward the previous result
                // Option 2: Take the current coin if possible
                int take = INT_MAX;
                if (coins[index] <= Target) {
                    take = 1 + curr[Target - coins[index]];  // Include the current coin and solve for the remaining amount
                }

                // Store the result in dp array and return the minimum of taking or not taking the coin
                curr[Target] = min(take, notTake);  // Store the minimum result between taking and not taking the coin
            }
            prev = curr;  // Update the previous state with the current state for the next iteration
        }

        // The answer is the minimum number of coins to make up the amount
        int ans = prev[amount];  
        return (ans >= 1e9) ? -1 : ans;  // If the answer is very large, it means it's not possible to form the amount
    }
};

EXPLANATION

Initialization of prev:
The base case where Target is 0 is handled such that no coins are needed (prev[0] = 0).
For other values, if Target is divisible by coins[0], the minimum number of coins needed is stored; otherwise, a large number (1e9) is stored to indicate it's not possible with just the first coin.

Dynamic Programming Transition:
The prev vector keeps the results of the previous iteration.
The curr vector is used to store the results of the current iteration.
For each index, we decide whether to take the current coin or not, and update the curr vector accordingly.

Updating States:
After processing all targets for the current coin index, the prev vector is updated to be the same as curr, which holds the current results.

Final Result:
The answer is found in prev[amount].
If the answer is greater than or equal to 1e9, it means the amount cannot be formed with the given coins, so we return -1. Otherwise, we return the answer.

