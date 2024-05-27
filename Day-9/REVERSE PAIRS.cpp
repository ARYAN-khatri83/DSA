class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(nums[i]>2*nums[j]){ // basic cond that needs to be followed in order to cal reverse pairs
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
