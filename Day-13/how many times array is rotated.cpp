#include<bits/stdc++.h>
int findKRotation(vector<int> &nums){
    // Write your code here.    
    int n = nums.size() - 1;
    int low = 0 , high = n; // low -> start , high -> end
    int ans = INT_MAX;
    int index =-1;
    while(low<=high){
        int mid = low + (high-low)/2;
            // serach space is already sorted
            // then always nums[low] will be smaller in that search space
        if(nums[low]<=nums[high]){
            if(nums[low]<ans){
                index = low;
                ans = nums[low];
            }
            break;
        }
            
        if(nums[low]<=nums[mid]) // left part is sorted
        {
            if(nums[low] <ans){
                index = low;
                ans = nums[low];
            }
            low = mid+1;
        }
        else{
            high = mid-1;
            if(nums[mid]<ans){
                index = mid;
                ans = nums[mid];
            }  // this is the right part and the mid will 
        }                    // always be the smallest number
    }
    return index;
}
