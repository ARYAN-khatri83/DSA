// BRUTE
// TC-O(N3)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi  = INT_MIN;
        int n = nums.size();
        for(int i =0 ;i<n;i++){
            for(int j=i;j<n;j++){
                int sum = 0;
                 for(int k=i ; k<=j;k++){
                    sum+=nums[k];
                }
                maxi = max(maxi,sum);
            }
        }
        return maxi;
    }
};




// OPTIMAL SOLUTION 
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
