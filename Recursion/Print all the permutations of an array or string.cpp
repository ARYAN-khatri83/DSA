class Solution {
public:
    void findPermut(vector<int>& ds, vector<int>& nums, vector<vector<int>>& ans, vector<int>& frequency) {
        // Base case: if the current permutation is complete, add it to the result
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        // Iterate through the numbers
        for (int i = 0; i < nums.size(); i++) {
            if (!frequency[i]) {
                // Mark the number as used
                frequency[i] = 1;
                // Include the number in the current permutation
                ds.push_back(nums[i]);
                // Continue building the permutation
                findPermut(ds, nums, ans, frequency);
                // Backtrack: unmark the number and remove it from the current permutation
                ds.pop_back();
                frequency[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; // To store all the permutations
        vector<int> ds; // To store the current permutation
        vector<int> frequency(nums.size(), 0); // To track the usage of elements in nums

        findPermut(ds, nums, ans, frequency); // Start the recursive function
        return ans;
    }
};
