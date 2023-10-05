class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() - 1;
        int low = 0 , high = n; // low -> start , high -> end
        int ans = INT_MAX;
        while(low<=high){
            int mid = low + (high-low)/2;
            // serach space is already sorted
            // then always nums[low] will be smaller in that search space
            if(nums[low]<=nums[high]){
                ans = min(ans,nums[low]);
                break;
            }
            
            if(nums[low]<=nums[mid]) // left part is sorted
            {
                ans = min(nums[low],ans);
                low = mid+1;
            }
            else{
                ans = min(nums[mid],ans);
                high = mid-1;           // this is the right part and the mid will 
            }                           // always be the smallest number
        }
        return ans;
    }
};
