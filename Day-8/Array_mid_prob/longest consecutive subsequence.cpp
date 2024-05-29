#include <iostream>
#include <algorithm>
using namespace std;

int findLongestConseqSubseq(int arr[], int N) {
    if (N == 0) return 0;
    sort(arr, arr + N);
    int longestStreak = 1;
    int currentStreak = 1;
    for (int i = 1; i < N; i++) {
        if (arr[i] == arr[i - 1]) continue;
        if (arr[i] == arr[i - 1] + 1) {
            currentStreak++;
        } else {
            longestStreak = max(longestStreak, currentStreak);
            currentStreak = 1;
        }
    }
    longestStreak = max(longestStreak, currentStreak);
    return longestStreak;
}

int main() {
    int arr[] = {1, 9, 3, 10, 4, 20, 2, 2, 1, 3, 2, 1, 6, 8, 7, 6, 5, 11, 12, 14, 13, 15, 17, 18, 16, 15, 14, 19, 23, 22, 21, 25, 24, 30, 29, 28, 27, 26, 25, 35, 34, 33, 32, 31, 40, 39, 38, 37, 36, 35, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91};
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of the Longest consecutive subsequence is " << findLongestConseqSubseq(arr, N) << endl;
    return 0;
}
