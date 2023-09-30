class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sums=0;
        int maxi = INT_MIN;

        for(int i=0;i<nums.size();i++){
            sums += nums[i];
            if(sums>maxi){
                maxi=sums;
            }
            if(sums<0){
                sums=0;
            }
        }
        return maxi;
    }
};
