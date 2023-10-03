int firstOccurance(vector<int> &arr, int n , int k){
    int start = 0;
    int end = n-1;
    int first = -1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid] == k){
            first=mid;
            end = mid-1;
        }
        else if(arr[mid] < k){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return first;
}

int lastoccurance(vector<int> &arr, int n , int k){
    int start = 0;
    int end = n-1;
    int last = -1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid] == k){
            last=mid;
            start = mid+1;
        }
        else if(arr[mid] < k){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return last;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int first = firstOccurance(arr,n,k);
    if(first == -1) return {-1,-1};
    int last = lastoccurance(arr,n,k);
    return {first,last};
}
int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here
	pair<int,int> ans = firstAndLastPosition(arr, n, x);
	if(ans.first == -1) return 0;
	return ans.second - ans.first+1;
}
