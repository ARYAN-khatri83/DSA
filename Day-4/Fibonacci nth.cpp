#include<iostream>
using namespace std;
int fibonaci(int n){
    int a = 0;
    int b = 1;
    for(int i =2;i<=n;i++){
        int sum = a+b;
        a=b;
        b=sum;
    }
    return b;
}
int main()
{
    int n;
    cin >> n;
    
    cout << "The " <<n<<"th term of the series is = "<< fibonaci(n) << endl;

    return 0;
}
