// Brute force Tc- O(n3) as we r running 3 loops and O(logn) for set map


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>st;
        for(int i =0 ;i<n;i++){
            for(int j = i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k] == 0){
                        vector<int> temp = {nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end()); // this is done in order to check if there is any duplicae triplet present and then we are storing in a set to check the same
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};



// Better approach TC-O(N2) SC -  O(2 * no. of the unique triplets) + O(N) as we are using a set data structure and a list to store the triplets and extra O(N) for storing the array elements in another set.
Algorithm:
The steps are as follows:

1. First, we will declare a set data structure as we want unique triplets.
2. Then we will use the first loop(say i) that will run from 0 to n-1.
3. Inside it, there will be the second loop(say j) that will run from i+1 to n-1.
4. Before the second loop, we will declare another HashSet to store the array elements as we intend to search for the third element using this HashSet.
5. Inside the second loop, we will calculate the value of the third element i.e. -(arr[i]+arr[j]).
6. If the third element exists in the HashSet, we will sort these 3 values i.e. arr[i], arr[j], and the third element, and insert it in the set data structure declared in step 1.
7. After that, we will insert the j-th element i.e. arr[j] in the HashSet as we only want to insert those array elements that are in between indices i and j.
8 .Finally, we will return a list of triplets stored in the set data structure.


  class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        int n = nums.size();
        for(int i = 0 ;i<n;i++){
            set<int> hashset; // the hashset always re intialises that is it gets empty whenever the i values changes or getss incremented
            for(int j=i+1;j<n;j++){
                int third = -(nums[i]+nums[j]);
                if(hashset.find(third) != hashset.end()){
                    vector<int>temp = {nums[i],nums[j],third};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[j]); // everytime j moves accumulate the numebr into hashset
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};



// OPTIMAL SOLU
AlGO
1. First, we will sort the entire array.
2. We will use a loop(say i) that will run from 0 to n-1. This i will represent the fixed pointer. In each iteration, this value will be fixed for all different values of the rest of the 2 pointers. Inside the loop, we will first check if the current and the previous element is the same and if it is we will do nothing and continue to the next value of i.
3. After that, there will be 2 moving pointers i.e. j(starts from i+1) and k(starts from the last index). The pointer j will move forward and the pointer k will move backward until they cross each other while the value of i will be fixed.
4. Now we will check the sum i.e. arr[i]+arr[j]+arr[k].
5. If the sum is greater, then we need lesser elements and so we will decrease the value of k(i.e. k--). 
6. If the sum is lesser than the target, we need a bigger value and so we will increase the value of j (i.e. j++). 
7. If the sum is equal to the target, we will simply insert the triplet i.e. arr[i], arr[j], arr[k] into our answer and move the pointers j and k skipping the duplicate elements(i.e. by checking the adjacent elements while moving the pointers).
8. Finally, we will have a list of unique triplets.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> ans;
       sort(nums.begin(),nums.end());
       int n = nums.size();
       for(int i = 0;i<n;i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        int j = i+1;
        int k=n-1;

        while(j<k){  // will move until j did not cross k
            int sum = nums[i]+nums[j]+nums[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else{
                vector<int> temp = {nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                // j and k cant be same so 
                j++;
                k--;

                // to check if the previous number are not same 
                while(j<k && nums[j] == nums[j-1]) j++;
                while(j<k && nums[k] == nums[k+1]) k--;
            }
        }
       }   
        return ans;
       
    }
};


Time Complexity: O(NlogN)+O(N2), where N = size of the array.
Reason: The pointer i, is running for approximately N times. And both the pointers j and k combined can run for approximately N times including the operation of skipping duplicates. So the total time complexity will be O(N2). 

Space Complexity: O(no. of quadruplets), This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).
