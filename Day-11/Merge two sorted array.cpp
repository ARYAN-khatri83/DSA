class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
       /* long long nums3[n+m];
        int left = 0;
        int right = 0;
        int index = 0;
        while(left< n && right<m){
            if(nums1[left]<=nums2[right]){
                nums3[index] = nums1[left];
                left++;index++;
            }
            else{
                nums3[index] = nums2[right];
                right++;index++;
            }
        }

        while(left<n){
            nums3[index++] = nums1[left++];
        }
        while(right<n){
            nums3[index++] = nums2[right++];
        }

        for(int i =0;i<n+m;i++){
            if(i<n) nums1[i] = nums3[i];
            else nums2[i-n] = nums3[i];
        }
        */

        int left = n-1;
        int right = 0;
        while(left >= 0 && right<m){
            if(nums1[left]>nums2[right]){
                swap(nums1[left],nums2[right]);
                left--;
                right++;
            }
            else{
                break;
            }
        }
        sort(nums1.begin(),nums1.begin()+n);
        sort(nums2.begin(),nums2.end());

        for(int i =n; i<m+n;i++){
            nums1[i]= nums2[i-n];
        }
    }
};
