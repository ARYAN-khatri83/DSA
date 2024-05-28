// BRUTE , IT WILL BE APPLICABLE IF THERE ARE NO EXTRA SPCAE

// ALGO
1. We will first declare a third array, arr3[] of size n+m, and two pointers i.e. left and right, one pointing to the first index of arr1[] and the other pointing to the first index of arr2[].
2. The two pointers will move like the following:
3. If arr1[left] < arr2[right]: We will insert the element arr1[left] into the array and increase the left pointer by 1.
4. If arr2[right] < arr1[left]: We will insert the element arr2[right] into the array and increase the right pointer by 1.
5. If arr1[left] == arr2[right]: Insert any of the elements and increase that particular pointer by 1.
6. If one of the pointers reaches the end, then we will only move the other pointer and insert the rest of the elements of that particular array into the third array i.e. arr3[].
7. If we move the pointer like the above, we will get the third array in the sorted order.
8. Now, from sorted array arr3[], we will copy first n(size of arr1[]) elements to arr1[], and the next m(size of arr2[]) elements to arr2[].



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        long long nums3[m+n];
        int left = 0;
        int right = 0;
        int index = 0 ; // for 3rd array

        while(left<n && right<m){
            if(nums1[left] <= nums2[right]){
                nums3[index] = nums1[left];
                index++,left++;
            }
            else{
                nums3[index] = nums2[right];
                index++,right++;
            }
        }

        while(left<n){
            nums3[index++]=nums1[left++];
        }
        while(right<n){
            nums3[index++]=nums2[right++];
        }

        for(int i =0; i<n+m ;i++){
            if (i < n) nums1[i] = nums3[i];
            else nums2[i - n] = nums3[i];
        }
    }
};



// OPTMIAL

The steps are as follows:

1. We will declare two pointers i.e. left and right. The left pointer will point to the last index of the arr1[](i.e. Basically the maximum element of the array). The right pointer will point to the first index of the arr2[](i.e. Basically the minimum element of the array).
2. Now, the left pointer will move toward index 0 and the right pointer will move towards the index m-1. While moving the two pointers we will face 2 different cases like the following:
3. If arr1[left] > arr2[right]: In this case, we will swap the elements and move the pointers to the next positions.
4. If arr1[left] <= arr2[right]: In this case, we will stop moving the pointers as arr1[] and arr2[] are containing correct elements.
Thus, after step 2, arr1[] will contain all smaller elements and arr2[] will contain all bigger elements. Finally, we will sort the two arrays.


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = n - 1; // Correct index for the end of the initial valid elements in nums1
        int right = 0; // Correct starting index for nums2

        // Sort nums1 and nums2 as per the merging requirements
        while (left >= 0 && right < m) {
            if (nums1[left] > nums2[right]) {
                // Swap elements to ensure nums1 contains the smaller elements and nums2 the larger
                swap(nums1[left], nums2[right]);
            } else {
                break;
            }

            // Move the pointers
            left--;
            right++;

            // Sort nums1 and nums2 to ensure the swapped elements are in the correct order
            sort(nums1.begin(), nums1.begin() + n);
            sort(nums2.begin(), nums2.begin()+ m);
        }

        // Copy the remaining elements of nums2 to nums1
        for (int i = 0; i < n; ++i) {
            nums1[m + i] = nums2[i];
        }
    }
};
