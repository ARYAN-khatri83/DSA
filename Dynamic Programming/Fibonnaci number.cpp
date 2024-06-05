// Memoization Approach

class Solution {
public:
    // Function to compute the nth Fibonacci number using memoization
    int fib(int n) {
        // Create a memoization table initialized with -1 (indicating uncomputed values)
        vector<int> memo(n + 1, -1);
        // Compute the nth Fibonacci number using the helper function
        return fibHelper(n, memo);
    }

private:
    // Helper function to compute Fibonacci number with memoization
    int fibHelper(int n, vector<int>& memo) {
        // Base cases
        if (n <= 1) {
            return n;
        }

        // Check if the value is already computed and stored in the memo table
        if (memo[n] != -1) {
            return memo[n];
        }

        // Compute the value and store it in the memo table
        memo[n] = fibHelper(n - 1, memo) + fibHelper(n - 2, memo);

        // Return the computed value
        return memo[n];
    }
};

// TABULATION METHOD
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        vector<int> dp(n + 1); // Use vector for dynamic memory allocation
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

TC- O(N) SC - O(N) TO MAKE SC-O(1)
    // SPACE OPTMIZATION 
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        int prev2 = 0;
        int prev = 1;
        for (int i = 2; i <= n; i++) {
            int curr_i = prev + prev2;
            prev2 = prev;
            prev = curr_i;
        }
        return prev;
    }
};

