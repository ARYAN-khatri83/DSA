

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

       //  BASIC APPROACH TC = O(N2)
        /* 
        int n = nums.size();
        for(int i = 0; i< n-1 ; i++){
        for(int j = i+1 ;j<n;j++){
         if(nums[i]+nums[j] == target;{
         return {i,j};
         }
         }
         }

    */




  // MEDIUM APPROACH  TC O(N) * LOG(N) SC = O(N)
        /*
     class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp; // declaration of map
        int n = nums.size();
        for(int i = 0 ;i<n ;i++){
            int num = nums[i];
            int more_nedded = target-num;
            if(mpp.find(more_nedded) != mpp.end()){
                return {mpp[more_nedded],i};
            }
            mpp[num] = i;
        }
        return {};

    }
};


*/


        // OPTIMAL APPROACH
// unordered map will increase the efficiency TC = O(n) * logn ,  SC = O(1)
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i = 0 ;i<n;i++){
            int a = target-nums[i];
            if(mpp.count(a)){
                return{mpp[a],i};
            }
            mpp[nums[i]]=i;
        }
        return {};
    }

};
