class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), max_pre = 0, max_suff = 0, ans = 0;
        vector<int> pre(n), suff(n);
        for(int i = 0 ; i < n ; i++){
            pre[i] = max_pre;
            max_pre = max(max_pre, height[i]);
        }
        for(int i = n - 1 ; i >= 0 ; i--){
            suff[i] = max_suff;
            max_suff = max(max_suff, height[i]);
            ans += max(0, min(suff[i], pre[i]) - height[i]);
        }
        return ans;
    }
};
