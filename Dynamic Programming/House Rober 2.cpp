class Solution {
public:

    public:
    int rob1(vector<int>& nums1) {
        int n = nums1.size();
        int prev = nums1[0];
        int prev2 = 0;

        for(int i =1 ;i<n;i++){
            int take = nums1[i];
            if(i>1){
                take+=prev2;
            }
            int not_take = 0+prev;
            int curr_i = max(take,not_take);
            prev2 = prev;
            prev= curr_i; 
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        int n = nums.size();
        if(n==1) return nums[0];
        for(int i =0;i<n;i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        return max(rob1(temp1),rob1(temp2));
    }
};
