// BRUTE 

The steps are as follows:

1. First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = size of the array).
2. Inside the loop, we will run another loop(say j) that will signify the ending index of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
3. After that for each subarray starting from index i and ending at index j (i.e. arr[i….j]), we will run another loop to calculate the sum of all the elements(of that particular subarray).
4. After calculating the sum, we will check if the sum is equal to the given k. If it is, we will increase the value of the count.

  Time Complexity: O(N3), where N = size of the array.


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(); // size of the given array.
        int cnt = 0; // Number of subarrays:

    for (int i = 0 ; i < n; i++) { // starting index i
        for (int j = i; j < n; j++) { // ending index j

            // calculate the sum of subarray [i...j]
            int sum = 0;
            for (int K = i; K <= j; K++)
                sum += nums[K];

            // Increase the count if sum == k:
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
        
    }
    
};


//OPTIMAL 

1. First, we will declare a map to store the prefix sums and their counts.
2. Then, we will set the value of 0 as 1 on the map.
3. Then we will run a loop(say i) from index 0 to n-1(n = size of the array).
4. For each index i, we will do the following:
We will add the current element i.e. arr[i] to the prefix sum.
We will calculate the prefix sum i.e. x-k, for which we need the occurrence.
We will add the occurrence of the prefix sum x-k i.e. mpp[x-k] to our answer.
Then we will store the current prefix sum in the map increasing its occurrence by 1.
  
  Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.

  
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       map<int,int> mpp;
       mpp[0]=1;
      int n = nums.size();
      int presum = 0, cnt = 0;
      for(int i =0;i<n;i++){
        presum += nums[i];
        int remove = presum - k;
        cnt+=mpp[remove];
        mpp[presum]+=1;
      }
      return cnt;
        
    }

    
};
