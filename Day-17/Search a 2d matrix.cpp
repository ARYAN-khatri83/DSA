class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size(); //size of first element of matrix vector. Suppose matrix is empty, then this will give you a segmentation fault or undefined behavior.
        int low = 0, high = n*m-1;
        while(low<=high){
            int mid = (low+high)/2;
            int row = mid/m;
            int col = mid%m;
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) low = mid+1;
            else{
                high = mid-1;
            }
        }
        return false;
    }
};
