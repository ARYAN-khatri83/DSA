class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);  // Initialize the result array with -1
        stack<int> s;  // Stack to keep indices of the elements

        for (int i = 0; i < 2 * n; ++i) {
            // Circular index
            int circularIndex = i % n;

            // Check if the current number is greater than the number at the index stored in the stack
            while (!s.empty() && nums[s.top()] < nums[circularIndex]) {
                result[s.top()] = nums[circularIndex];
                s.pop();
            }

            // Push the index to the stack only if we are in the first pass
            if (i < n) {
                s.push(circularIndex);
            }
        }

        return result;
    }
};
