#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        // Initialize the answer string to be empty
        string ans = "";

        // Sort the vector of strings lexicographically
        sort(v.begin(), v.end());

        // Get the number of strings in the vector
        int n = v.size();

        // Edge case: if the vector is empty, return the empty answer string
        if (n == 0) return ans;

        // Get the first and the last strings in the sorted vector
        string first = v[0];
        string last = v[n-1];

        // Compare characters of the first and last strings
        // The common prefix of the entire vector will be the common prefix
        // of the first and last strings after sorting
        for (int i = 0; i < min(first.size(), last.size()); i++) {
            // If characters at the current position are not the same, return the current answer
            if (first[i] != last[i]) {
                return ans;
            }
            // If characters are the same, add the character to the answer
            ans += first[i];
        }

        // If loop completes, the entire shorter string is a common prefix
        return ans;
    }
};
