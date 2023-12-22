class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() < 2) return s.size();
        int left = 0;
        int right = 0;
        int maxlen = INT_MIN;
        unordered_set <char> us;
        while(right != s.size()) {
            if(us.find(s[right]) == us.end()) {
                maxlen = max(right-left+1, maxlen);
               // right++;
                us.insert(s[right++]);
               // right++;
            } else{
               // left++;
                us.erase(s[left++]);
               // left++;
            } 
        }
        return maxlen;
    }
    };
