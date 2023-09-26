#include<iostream>
using namespace std;
int setbitsA(int a){
    int count =0 ;
    while(a!=0){
        if(a&1){
            count++;
        }
        a=a>>1;
    }
    return count;
}

int setbitsB(int b){
    int count = 0;
    while(b!=0){
        if(b&1){
            count++;
        }
        b=b>>1;
    }
    return count;
}

int main(){
    int a , b;
    cin>>a>>b;
    int ans = setbitsA(a);
    int ans1 = setbitsB(b);
    cout<<"Setbits of A is " << ans << endl;
    cout<< "Setbits of B is " << ans1 << endl;

    int total = ans+ans1;
    cout<< " total setbits are : " << total << endl; 
}
