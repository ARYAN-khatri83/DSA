class Solution {
public:
    std::string reverseVowels(std::string s) {
        std::string vowels = "AEIOUaeiou";
        std::string vow = "";
        for (char c : s) {
            if (vowels.find(c) != std::string::npos) {
                vow += c;
            }
        }
        std::reverse(vow.begin(), vow.end());
        int i = 0;
        for (char& c : s) {
            if (vowels.find(c) != std::string::npos) {
                c = vow[i++];
            }
        }
        return s;
    }
};
