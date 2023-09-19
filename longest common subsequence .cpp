class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       /* BETTER SOL
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int count = 0;
        int last_smallest=INT_MIN;
        int longest=1;
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]-1 == last_smallest){
                count = count+1;
                last_smallest=nums[i];
            }
            else if(last_smallest!=nums[i]){
                count=1;
                last_smallest=nums[i];
            }
            longest=max(longest,count);
        }
        return longest;
        */


        // OPTIMAL SOL
        int n=nums.size();
        if(n==0) return 0;
        int longest=1;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }

        for(auto it:st){
            if(st.find(it-1) == st.end()){
                int cnt=1;
                int x=it;
                while(st.find(x+1) != st.end()){
                    x=x+1;
                    cnt = cnt+1;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;

    }
};
