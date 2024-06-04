QUESTION
Given an integer array nums that may contain duplicates, return all possible 
subsets (the power set).
 

class Solution {
public:
    void backtrack(int index , vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
        ans.push_back(ds);
        for (int i = index; i < nums.size(); ++i) {
            // Skip duplicates
            if (i > index && nums[i] == nums[i - 1]) continue;

            // Include nums[i] in the ds subset
            ds.push_back(nums[i]);

            // Recur with the next index
            backtrack(i + 1, nums, ds, ans);

            // Backtrack: remove the last element before the next iteration
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;

        // Sort the array to handle duplicates
        sort(nums.begin(), nums.end());

        // Start the backtracking
        backtrack(0, nums, ds, ans);

        return ans;
    }
};
