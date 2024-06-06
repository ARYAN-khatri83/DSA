class Solution {
public:
    // Helper function to calculate the maximum amount robbed for a linear street of houses
    int rob1(vector<int>& nums1) {
        int n = nums1.size();
        
        // Base case: if there's only one house, return its value
        if (n == 1) return nums1[0];

        // Initialize variables to store the maximum amount robbed up to the previous two houses
        int prev = nums1[0];
        int prev2 = 0;

        // Iterate through the houses starting from the second house
        for (int i = 1; i < n; i++) {
            int take = nums1[i]; // Amount robbed if we take the current house
            if (i > 1) {
                take += prev2; // Add the amount robbed from the house before the last
            }
            int not_take = prev; // Amount robbed if we skip the current house
            int curr_i = max(take, not_take); // Choose the maximum of taking or not taking the current house
            prev2 = prev; // Update prev2 to the previous house's value
            prev = curr_i; // Update prev to the current house's value
        }
        
        return prev; // Return the maximum amount robbed up to the last house
    }

    // Main function to calculate the maximum amount robbed for houses in a circular street
    int rob(vector<int>& nums) {
        vector<int> temp1, temp2;
        int n = nums.size();

        // Base case: if there's only one house, return its value
        if (n == 1) return nums[0];

        // Create two scenarios: excluding the first house or excluding the last house
        for (int i = 0; i < n; i++) {
            if (i != 0) temp1.push_back(nums[i]); // Exclude the first house
            if (i != n - 1) temp2.push_back(nums[i]); // Exclude the last house
        }
        
        // Return the maximum amount robbed between the two scenarios
        return max(rob1(temp1), rob1(temp2));
    }
};
