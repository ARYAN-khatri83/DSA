#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, maxLen = 0, zeroes = 0;

        while (right < nums.size()) {
            if (nums[right] == 0) {
                zeroes++;
            }

            while (zeroes > k) {
                if (nums[left] == 0) {
                    zeroes--;
                }
                left++;
            }

            if (zeroes <= k) {
                int len = right - left + 1;
                maxLen = max(maxLen, len);
            }

            right++;
        }

        return maxLen;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 0, 1, 1, 0, 0, 1, 1, 1};
    int k = 2;
    int result = sol.longestOnes(nums, k);
    // Output should be 6, as the longest subarray with at most 2 zeros is [1, 1, 0, 1, 1, 0]
    cout << result << endl;
    return 0;
}
