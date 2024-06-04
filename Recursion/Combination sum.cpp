QUESTION
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates 
where the chosen numbers sum to target. 
You may return the combinations in any order.The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the frequencyof at least one of the chosen numbers is different.



class Solution {
public:
    void findCombinations(int index, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds) {
        // Base case: if the target is met, add the current combination to the result
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        // Iterate through the candidates starting from the current index
        for (int i = index; i < candidates.size(); ++i) {
            // If the current candidate is greater than the remaining target, no need to continue
            if (candidates[i] > target) break;

            // Include the current candidate in the combination
            ds.push_back(candidates[i]);
            // Continue the search with the updated target and same index (allowing the same number to be used again)
            findCombinations(i, target - candidates[i], candidates, ans, ds);
            // Backtrack and remove the last added candidate from the combination
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Result vector to store all the unique combinations
        vector<vector<int>> ans;
        // Temporary vector to store the current combination
        vector<int> ds;
        // Sort the candidates to facilitate early stopping in the recursion
        sort(candidates.begin(), candidates.end());
        // Start the recursive search for combinations
        findCombinations(0, target, candidates, ans, ds);
        return ans;
    }
};


1. Sorting: The candidates array is sorted to help with early termination in the recursion (if (candidates[i] > target) break;). 
This ensures that once the target is exceeded, no further elements need to be considered.
2. Backtracking: The ds vector is used to store the current combination of numbers. 
   When a combination is complete (i.e., the target is reached), it is added to the ans vector. 
   The last element is then removed to explore other potential combinations.
3. Recursive Calls: The function findCombinations is called recursively, allowing the same number to be used multiple times.
  This is achieved by passing the current index (i) rather than i + 1.
