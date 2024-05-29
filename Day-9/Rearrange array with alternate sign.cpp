// BRUTE
//APPROACH
1. In this simple approach, since the number of positive and negative elements are the same, we put positives into an array called “pos” and negatives into an array called “neg”.
2. After segregating each of the positive and negative elements, we start putting them alternatively back into array A.
3. Since the array must begin with a positive number and the start index is 0, so all the positive numbers would be placed at even indices (2*i) and negatives at the odd indices (2*i+1), where i is the index of the pos or neg array while traversing them simultaneously.
    
    
This approach uses O(N+N/2) of running time due to multiple traversals which we’ll try to optimize in the optimized approach given below.

// code
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i]>0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }

        for(int i =0 ;i<n/2 ;i++){
            nums[2*i] = pos[i];
            nums[2*i+1] = neg[i];
        }
        return nums;
    }
};

//OPTIMAL

Approach:

1. In this optimal approach, we will try to solve the problem in a single pass and try to arrange the array elements in the correct order in that pass only.
2. We know that the resultant array must start from a positive element so we initialize the positive index as 0 and negative index as 1 and start traversing the array such that whenever we see the first positive element, it occupies the space at 0 and then posIndex increases by 2 (alternate places).
3. Similarly, when we encounter the first negative element, it occupies the position at index 1, and then each time we find a negative number, we put it on the negIndex and it increments by 2.
When both the negIndex and posIndex exceed the size of the array, we see that the whole array is now rearranged alternatively according to the sign.

    
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
    // Define array for storing the ans separately.
        vector<int> ans(n,0);
        
  // positive elements start from 0 and negative from 1.
        int posIndex = 0 , negIndex = 1;

  // Fill negative elements in odd indices and inc by 2.
        for(int i =0;i<n;i++){
            if(nums[i]<0){
                ans[negIndex] = nums[i];
                negIndex+=2;
            }     // Fill positive elements in even indices and inc by 2.
            else{
                ans[posIndex] = nums[i];
                posIndex +=2;
            }
        }
        return ans;
    }
};
