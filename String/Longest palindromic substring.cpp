
    class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int n = s.size();
        int start = 0, maxLength = 1;

        // Helper function to expand around the center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            int length = right - left - 1;
            if (length > maxLength) {
                start = left + 1;
                maxLength = length;
            }
        };

        for (int i = 0; i < n; ++i) {
            // Expand around single character center (odd length palindromes)
            expandAroundCenter(i, i);
            // Expand around double character center (even length palindromes)
            expandAroundCenter(i, i + 1);
        }

        return s.substr(start, maxLength);
    }
};
