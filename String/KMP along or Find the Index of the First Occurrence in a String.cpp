class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();  // Get the length of the needle
        string str;  // Temporary string to hold substrings from haystack

        // Iterate through the haystack
        for (int i = 0; i < haystack.size(); i++) {
            // Check if the current character in haystack matches the first character in needle
            if (needle[0] == haystack[i]) {
                // Extract a substring of length n starting from the current position i
                str = haystack.substr(i, n);
                
                // Compare the extracted substring with the needle
                if (str == needle) {
                    // If they are equal, return the current index i
                    return i;
                }
            }
        }
        
        // If the needle is not found in the haystack, return -1
        return -1;
    }
};
