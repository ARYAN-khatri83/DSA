

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        map<int,int> mpp;
        int n=nums.size();
        for(int i =0;i<n;i++){
            int a = nums[i];
            int more = target-a;
            if(mpp.find(more) != mpp.end()){
                return {mpp[more],i};
            }
            mpp[a]=i;
        }
        return {};
        */

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
