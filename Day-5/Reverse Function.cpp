#include<iostream>
using namespace std;
void Reverse(int arr[], int start, int end){
    while(start<=end){
        int temp = arr[start];
        arr[start]= arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
