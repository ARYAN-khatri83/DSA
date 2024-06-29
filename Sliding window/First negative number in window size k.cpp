#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class FirstNegativeInWindowSizeK {
public:
    static vector<int> solve(const vector<int>& arr, int k) {
        // Given an array of length n, and sliding window size k
        // Total sub-arrays possible are n - k + 1
        vector<int> ans(arr.size() - k + 1);

        // Maintaining a list of negatives (FIFO) structure to hold the negatives that are encountered in the original array
        queue<int> negatives;

        // Left and right pointers to move in the array
        int left = 0, right = 0;

        // Pointer to keep track of index in ans
        int ptr = 0;

        // Iterate till right is less than overall length
        while (right < arr.size()) {
            // Find right most element
            int ele = arr[right];
            // If negative, add it to the queue
            if (ele < 0) {
                negatives.push(ele);
            }

            // If window size is not reached, increase the window size by moving right pointer
            if (right - left + 1 < k) {
                right++;
            } else if (right - left + 1 == k) {
                // If window size is reached, we need additional logic as demanded in the question
                // If the negatives queue is empty, that means no negative element encountered so far
                // so simply add a 0 to the answer/result array
                if (negatives.empty()) {
                    ans[ptr++] = 0;
                } else {
                    // In case the negatives queue is not empty, that means we have seen some negative elements in the current sliding window
                    // Peek the queue to find the element and store it in the answer array
                    ans[ptr++] = negatives.front();
                    // If the topmost element is same as the leftmost element
                    // then also remove it from the queue
                    if (arr[left] == negatives.front()) {
                        negatives.pop();
                    }
                }
                // Finally, increase both left and right pointers to slide the window
                left++;
                right++;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> arr = {12, -1, -2, 8, -16, 30, 16, 28};
    int k = 3;

    vector<int> result = FirstNegativeInWindowSizeK::solve(arr, k);

    // Print the result
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
