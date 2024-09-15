class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize a vector to store the result
        vector<int> result(n, 0);
        
        // Variable to keep track of the product of elements from the right side
        long long product_right = 1;
        
        // Calculate product of elements to the right of each element
        for(int i = n - 1; i >= 0; i--) {
            product_right *= nums[i];
            result[i] = product_right;
        }

        // Variable to keep track of the product of elements from the left side
        long long product_left = 1;
        
        // Calculate product of elements to the left of each element
        for(int i = 0; i < n - 1; i++) {
            result[i] = result[i + 1] * product_left;
            product_left *= nums[i];
        }
        
        // Update the last element of the result array
        result[n - 1] = product_left;

        return result;
    }
};
