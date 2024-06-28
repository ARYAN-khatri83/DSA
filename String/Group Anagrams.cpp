
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map to store sorted string as key and list of anagrams as value
        unordered_map<string, vector<string>> mp;
        
        for (auto it : strs) {
            // Copy the original string to temp
            string temp = it;
            // Sort the original string to get the key
            sort(it.begin(), it.end());
            // Use the sorted string as key and append the original string to the corresponding list
            mp[it].push_back(temp);
        }
        
        // Build the final answer
        vector<vector<string>> ans;
        for (auto x : mp) {
            ans.push_back(x.second);
        }
        
        // Return the result
        return ans;
    }
};
