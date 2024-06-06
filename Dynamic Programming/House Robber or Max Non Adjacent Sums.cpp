// Recursion 
class Solution {
public:
    int f(int index , vector<int>& nums){
        if(index == 0) return nums[index];
        if(index == 1) return 0;

        int pick = nums[index] + f(index-2,nums);
        int notPick = 0 + f(index-1,nums);
        return max(pick,notPick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        return f(n-1,nums);
    }
};

// Memoization

class Solution {
public:
    int f(int index , vector<int>& nums,vector<int> &dp){
        if(index == 0) return nums[index];
        if(index<0) return 0;

        if(dp[index] != -1) return dp[index];
        int pick = nums[index] + f(index-2,nums,dp);
        int notPick = 0 + f(index-1,nums,dp);
        return dp[index] = max(pick,notPick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(n-1,nums,dp);
    }
};

TC-O(N) SC_O(N) + O(N)


  // TABULATION WITH SPACE OPTIMIZATION
  class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;

        for(int i =1 ;i<n;i++){
            int take = nums[i];
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
};
