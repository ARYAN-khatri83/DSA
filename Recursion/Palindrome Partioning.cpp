class Solution {
public:
    // Main function to find all palindrome partitions
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res; // to store the final result
        vector<string> path; // to store the current path of substrings
        func(0, s, path, res); // start the recursion with the initial index 0
        return res;
    }

private:
    // Helper function for the recursive approach
    void func(int index, string s, vector<string>& path, vector<vector<string>>& res) {
        // If the current index reaches the end of the string, add the current path to the result
        if (index == s.size()) {
            res.push_back(path);
            return;
        }

        // Try to partition the string at every possible point
        for (int i = index; i < s.size(); i++) {
            // Check if the substring from index to i is a palindrome
            if (isPalindrome(s, index, i)) {
                // If it is, add the substring to the current path
                path.push_back(s.substr(index, i - index + 1));
                // Recurse to find further partitions starting from the next index
                func(i + 1, s, path, res);
                // Backtrack and remove the last added substring from the current path
                path.pop_back();
            }
        }
    }

    // Utility function to check if a substring is a palindrome
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};
