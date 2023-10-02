#include<bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    int n = a.size();
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ a[i];
        int x = xr ^ b;
        cnt = cnt + mpp[x];
        mpp[xr]++;
    }
    return cnt;
}
