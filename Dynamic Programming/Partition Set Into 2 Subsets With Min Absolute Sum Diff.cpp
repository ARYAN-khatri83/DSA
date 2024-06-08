class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;

        // Calculate the total sum of the array elements
        for (int i = 0; i < n; i++) {
            totSum += nums[i];
        }

        // Initialize a 2D DP array with false values
        vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));
        
        // Base case: A sum of 0 can always be achieved by not taking any elements
        for (int i = 0; i < n; i++) dp[i][0] = true;

        // Base case: If the first element is within the range, set it to true
       dp[0][nums[0]] = true;

        // Fill the DP array
        for (int index = 1; index < n; index++) {
            for (int target = 1; target <= totSum; target++) {
                // Option 1: Don't take the current element
                bool notTake = dp[index - 1][target];
                
                // Option 2: Take the current element, if possible
                bool take = false;
                if (nums[index] <= target) {
                    take = dp[index - 1][target - nums[index]];
                }
                
                // Current position is true if any of the two options is true
                dp[index][target] = notTake || take;
            }
        }

        int mini = INT_MAX;
        // Try to find the minimum difference
        for (int s1 = 0; s1 <= totSum / 2; s1++) {
            if (dp[n - 1][s1]) {
                mini = min(mini, abs(totSum - 2 * s1));
            }
        }

        return mini;
    }
};
