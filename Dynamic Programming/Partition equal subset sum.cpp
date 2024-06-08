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




1. Subset Sum Function (subsetSumEqualsToK):
This function checks if there is a subset of the given array arr that sums up to k.
Parameters:
n: Number of elements in the array.
k: Target sum we are trying to find within subsets.
arr: The array of integers.

2. DP Array Initialization:
dp is a 2D boolean array of size n x (k + 1) initialized to false. dp[i][j] will be true if a sum of j can be achieved using the first i elements.
Base Case:
dp[i][0] is set to true for all i because a sum of 0 can always be achieved by taking no elements.
If the first element arr[0] is less than or equal to k, then dp[0][arr[0]] is set to true.

3. DP Array Filling:
Iterate over all elements from the second one onwards.
For each element, iterate over all possible sums from 1 to k.
For each position (index, target), check two possibilities:
Not taking the current element: dp[index - 1][target]
Taking the current element (if it's not greater than target): dp[index - 1][target - arr[index]]
Combine these possibilities using the logical OR operator.

4. Result:
The value dp[n - 1][k] tells if it's possible to form a sum k using all n elements.

5. Main Function (canPartition):
This function determines if the array can be partitioned into two subsets with equal sum.
Total Sum Calculation:
Calculate the total sum of the array elements.
Check for Odd Total Sum:
If the total sum is odd, return false since it's impossible to split an odd number into two equal integer parts.

6. Target Calculation:
Set target as half of the total sum.
Subset Sum Check:
Use the helper function subsetSumEqualsToK to check if there exists a subset with sum equal to target.
Return Result:
Return the result from the helper function which determines if such a subset exists.
