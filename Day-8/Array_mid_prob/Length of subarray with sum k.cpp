#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& a, int k){
    // Write your code here
    map<long long , int> preSumMap;
    long long sum= 0;
    int maxlen=0;
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        if(sum==k){
            maxlen=max(maxlen,i+1);
        }
        long long rem = sum-k;
        if(preSumMap.find(rem)!=preSumMap.end()){
            int len = i-preSumMap[rem];
            maxlen = max(maxlen,len);
        }
        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum]=i;
        }
    }
    return maxlen;
}
