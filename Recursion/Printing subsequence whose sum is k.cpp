#include<iostream>
#include<vector>
using namespace std;

void PrintS(int ind, vector<int> &ds, int s, int sum, int arr[], int n) {
    if (ind == n) {
        if (s == sum) {
            for (auto it : ds) cout << it << " ";
            cout << endl;
        }
        return;
    }
    ds.push_back(arr[ind]);
    s += arr[ind];

    // Recursive call without popping the last element
    PrintS(ind + 1, ds, s, sum, arr, n);

    // Backtrack: pop the last element to explore other possibilities
    ds.pop_back();
    s -= arr[ind];

    // Recursive call without including the current element
    PrintS(ind + 1, ds, s, sum, arr, n);
}

int main() {
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    PrintS(0, ds, 0, sum, arr, n);
    return 0;
}
