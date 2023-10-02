#include<vector>

int getLongestZeroSumSubarrayLength(vector<int> &arr){
	// Write your code here.
	int n = arr.size();
	long long prefix_sum = 0;
	int ans = 0;
	
	// The hashmap to store the first index at which a prefix sum occurs.
	unordered_map<long long, int> first_index;
	first_index[0] = -1;
	
	// Traversing through the array.
	for(int i = 0; i < n; ++i){
		prefix_sum += arr[i];
		
		// Finding the longest length subarray ending at 'i' and having zero-sum.
		if(first_index.find(prefix_sum) != first_index.end())
			ans = max(ans, i - first_index[prefix_sum]);
		else
			first_index[prefix_sum] = i;
	} 
	return ans;
}
	
