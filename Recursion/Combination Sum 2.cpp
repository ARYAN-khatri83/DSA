QUESTION
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates
where the candidate numbers sum to target.Each number in candidates may only be used once in the combination.

class Solution {
public:
    // Helper function to find combinations
    void findCombination(int index, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
        // Base case: if the target is met, add the current combination to the result
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        
        // Iterate through the candidates starting from the current index
        for (int i = index; i < arr.size(); i++) {
            // Skip duplicates
            if (i > index && arr[i] == arr[i - 1]) continue;
            // If the current candidate is greater than the remaining target, stop further processing
            if (arr[i] > target) break;
            
            // Include the current candidate in the combination
            ds.push_back(arr[i]);
            // Move to the next index and reduce the target by the current candidate's value
            findCombination(i + 1, target - arr[i], arr, ans, ds);
            // Backtrack: remove the last added candidate from the combination
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Sort the candidates to handle duplicates and facilitate early stopping
        sort(candidates.begin(), candidates.end());
        // Result vector to store all unique combinations
        vector<vector<int>> ans;
        // Temporary vector to store the current combination
        vector<int> ds;
        // Start the recursive search for combinations
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};
