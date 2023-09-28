class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end()); // here we r rotationg the whole arr
        reverse(nums.begin(), nums.begin()+k); // first k elements
        reverse(nums.begin()+k, nums.end()); // n-k elements
    }
};
