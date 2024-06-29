class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
       if (nums.size() < k) return 0; // If there are fewer elements than k, return 0 or an appropriate value

        int i = 0, j = 0;
        long long sum = 0;
        long long maxSum = LLONG_MIN; 

        while (j < nums.size()) {
            sum += nums[j];

            if (j - i + 1 < k) {
                j++;
            }
            else if (j - i + 1 == k) {
                maxSum = max(maxSum, sum);
                sum -= nums[i];
                i++;
                j++;
            }
        }

        return maxSum;
    }
};
