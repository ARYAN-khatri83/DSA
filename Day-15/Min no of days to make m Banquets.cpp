class Solution {
public:
    bool possible(vector<int> &bloomDay , int day , int m , int k){
        int cnt = 0;
        int no_of_B = 0;
        for(int i = 0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                cnt++;
            }
            else{
                no_of_B += (cnt/k);
                cnt = 0;
            }
        }
        no_of_B += (cnt/k);
        return no_of_B >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k * 1ll;
        if(val>bloomDay.size()) {
            return -1;
        }
        /*
        int mini = INT_MAX , maxi = INT_MIN;
        for(int i =0;i<bloomDay.size();i++){
            mini = min(mini,bloomDay[i]);
            maxi = max(maxi,bloomDay[i]);
        }
        */
        int low = *min_element(bloomDay.begin(),bloomDay.end());

        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(possible(bloomDay,mid,m,k)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
