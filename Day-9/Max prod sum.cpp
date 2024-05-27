
// Brute TC-O(N3)

#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int>& nums) {
    int result = INT_MIN;
    for(int i=0;i<nums.size()-1;i++) {
        for(int j=i+1;j<nums.size();j++) {
            int prod = 1;
            for(int k=i;k<=j;k++) 
                prod *= nums[k];
            result = max(result,prod);    
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}


// Better TC-O(N2)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++){
            int prod = 1;
            for(int j=i;j<n;j++){
                prod *= nums[j]; // while writing this line check for i,j
                maxi = max(maxi,prod); 

            }
        }
        return maxi;
    }
};


// OPTIMAL TC-O(N)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // optimal
        int pre = 1 , suff = 1;
        int ans = INT_MIN;
        int n = nums.size();
        for(int i = 0 ;i<n;i++){
            if(pre==0){
                pre = 1;
            }
            if(suff==0){
                suff = 1;
            }

            pre*=nums[i]; // if the negative number is in between then it will divide the array in two which is a prefix part and a suffix 
            suff*=nums[n-i-1];
            ans = max(ans,max(pre,suff)); 
        }
        return ans;
    }
};
