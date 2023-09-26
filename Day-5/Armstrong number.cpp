//ARMSTRONG NUMBER
#include <iostream>
#include<math.h>
#include<string.h>
using namespace std;

int main(){
    int n;
    int sum = 0;
    int dup = n;
    // to find the len of a number in cpp  we use to_string(num).length()
    int order = to_string(n).length();

    while(n>0){
        int ld = n%10;
        sum += pow(ld,order);
        n = n/10;
    }
    if(sum == dup){
        cout<<"The given number is an Armstrong number";
    }
    else{
        cout<<"IT IS NOT AN ARMSTRONG NUMEBR";
    }
}
