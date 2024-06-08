class Solution {
    // Helper function to check if there's a subset that sums up to k
    bool subsetSumEqualsToK(int n, int k, vector<int>& arr) {
        // Initialize a 2D DP array with false values
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
        
        // Base case: A sum of 0 can always be achieved by not taking any elements
        for (int i = 0; i < n; i++) dp[i][0] = true;
        
        // Base case: If the first element is less than or equal to k, set it to true
        if (arr[0] <= k) dp[0][arr[0]] = true;

        // Fill the DP array
        for (int index = 1; index < n; index++) {
            for (int target = 1; target <= k; target++) {
                bool notTake = dp[index - 1][target];
                bool take = false;
                if (arr[index] <= target) {
                    take = dp[index - 1][target - arr[index]];
                }
                dp[index][target] = notTake || take;
            }
        }
        
        return dp[n - 1][k];
    }

public:
    // Main function to check if the array can be partitioned into two subsets with equal sum
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        
        // Calculate the total sum of the array
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

        // If the total sum is odd, it's not possible to partition into equal subsets
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;

        // Use the helper function to check for the subset sum
        return subsetSumEqualsToK(n, target, nums);
    }
};
