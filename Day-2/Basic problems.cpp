#include<iostream>
#include<math.h>
using namespace std;

/*
sum form 1 to n

int main(){
    int n;
    cout<<"Enter the number" << endl ; 
    cin>>n;

    int sum=0;

    for(int i=1;i<=n;i++){
        sum+=i;
    }
    cout<<sum<<endl;

}
*/

// FIBONNACI SERIES
/*
int main(){
   int n=10;

    int  a=0;
    int b=1;
    cout<<a<<" "<<b<<" ";
    for(int i=1;i<=n;i++){
        int sum=a+b;
        cout<<sum<<" ";
        a=b;
        b=sum;

    }
}
*/

// PRIME NUMBER CHECKER

/*
int main(){
    int n;
    cout<<"Enter a numebnr"<<endl;
    cin>>n;
    bool isPrime=1;

    for(int i=2;i<n;i++){
        if(n%i==0){
            //cout<<"Not a prime number"<<endl;
            isPrime=0;
            break;
        }
    }
    if(isPrime==0){
        cout<<"Not a Prime number";
    }
    else{
        cout<<"IS a prime numeber";
    }
}
*/

// DECIMAL TO BINARY
/*
int main(){
    int n;
    cin>>n;

    int answer=0;
    int i =0;
    while(n!=0){
        int bit = n & 1; 
        answer = (bit * pow(10,i))  + answer;
        n=n>>1;
        i++;
    }
    cout<< "Answer is " << answer << endl;
}
*/

// BINARY TO DECIMAL

/*
int main(){

    int n;
    cin>>n;

    int ans=0;
    int i =0;
    while(n!=0){
        int digit = n%10;
        if(digit==1){
            ans = ans+pow(2,i);
        }
        n=n/10;
        i++;
    }
    cout<<"Answer is " << ans << endl;
}
*/


//SWITCH CASE
/*
int main(){
    int amount;
    cin>>amount;

    int Rs100,Rs50,Rs20,Rs1;

    switch(1){
         case 1: Rs100=amount/100;
              amount=amount%100;
              cout<<"No of 100 Rupee ="<<Rs100<<endl;
              
         
      case 2: Rs50=amount/50;
              amount=amount%50;
              cout<<"No of 50 Rupee ="<<Rs50<<endl;
              

      case 3: Rs20=amount/20;
              amount=amount%20;
              cout<<"No of 20 Rupee ="<<Rs20<<endl;
               

      case 4: Rs1=amount/1;
              amount=amount%1;
              cout<<"No of 1 Rupee ="<<Rs1<<endl; 
          
           }
        return 0;
    }

    */
