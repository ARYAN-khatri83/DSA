#include<iostream>
using namespace std;


/*

int main()
{
    char ch ;
    cout<<"Enter the value of ch " <<endl;
    cin>>ch;

    if(ch > 96 && ch < 123) {
        cout<<"Lower case";
    }
    else if (ch > 64 && ch < 91)
    {
        cout<<"Upper case";
    }
    
    else if(ch>47 && ch < 58)
    {
        cout<<"Numeric";
    }
    else{
        cout<<"symbol" ;
    }
    return 0;
}


*/
// Prime or not prime
/*
int main()
{
    int n;
    cin >> n;
    
    int i = 2;
    while(i<n){
        if(n%i==0){
            cout<<" Not Prime " <<  i << endl;
        }

        else{
            cout<< " Prime Number" << i <<  endl;
        }
        i = i+1;
        
    }
}

*/
/* Print same stars in rows and column
int main(){
    int n;
    cin >> n;

    int i =1;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<< "*";
            j = j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

// PATTERN QUESTIONS

/*
int main(){
    int n;
    cin>> n;

    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n){ 
            cout<< n-j+1; // only j can be written to change 1 to 7
            j = j + 1;
        }
        cout<<endl;
        i=i+1;

    }
}
*/

 /*
int main(){
    int n;
    cin>>n;
   
    
    int i =1;
    int count = 1;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<< count << " " ;
            count = count+1;
            j = j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

/*

int main(){
    int n;
    cin>>n;

    int row = 1;
    while(row<=n){
        int col  = 1;
        while(col <= row){
            cout<<"*";
            col = col+1;
        }
        cout<<endl;
        row=row+1;
    }
}

*/
/*

int main(){

    int n;
    cin>>n;
    int row =1;
    while(row<=n){
        int col = 1;
        while(col<=row){
            cout<<row;
            col=col+1;
        }
        cout<<endl;
        row=row+1;
    }
}

*/

/*
int main(){
    int n;
    cin>>n;

    int i = 1, count = 1;
    while(i<=n){
        int j = 1;
        while(j<=i){
            cout<< count <<" ";
            count = count+1;
            j=j+1;
        }
        cout << endl;
        i=i+1;
    }
}
*/

/*
int main(){
    int n;
    cin>>n;

    int i =1;
    while(i<=n){
        int j =1;
        int value=i;
        while(j<=i){
           cout<<value;
           value = value+1;
           j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}

*/


/*
int main(){
    int n;
    cin>>n;

    int row= 1;
    while(row<=n){
        int col=1;
        while(col<=row){
            cout<<(row-col+1)<< " ";
            col=col+1;
        }
        cout<<endl;
        row=row+1;
    }
}


*/

/*

int main(){
    int n;
    cin>>n;

    int row = 1;
    while(row<=n){
        int col=1;
        while(col<=n){
            char ch = 'A' + row - 1;
            cout<< ch;
            col = col+1;
        }
        cout<<endl;
        row=row+1;

    }
}

*/

/*
int main(){
    int n;
    cin>>n;

    int row=1;
    while(row<=n){
        int col=1;
        while(col<=n){
            char ch = 'A' + col - 1;
            cout<<ch;
            col=col+1;
        }
        cout<<endl;
        row=row+1;
    }
}

 */


/*

int main(){
    int n;
    cin>>n;

    int i =1; 
    char ch='A';
    while(i<=n){
        int j=1;
        while(j<=n){
            cout << ch << " ";
            ch=ch+1;
            j=j+1;
        }
        cout<<endl;
        i=i+1;

    }
}

*/

/*
int main(){
    int n;
    cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            char ch = 'A'+i+j-2;
            cout<<ch<<" ";
            ch = ch+1;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}

*/

/*

int main(){
    int n;
    cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            char ch= ('A'+i-1);
            cout<<ch;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

/*
int main(){
    int n;
    cin>>n;

    int i =1;
    char ch  = 'A';
    while(i<=n){
        int j = 1;
        while(j<=i){
           cout<< ch << " ";
           ch=ch+1;
           j=j+1;

        }
        cout<<endl;
        i=i+1;

    }
}

*/

/*
int main(){
    int n;
    cin>>n;

    int i =1;
    while(i<=n){
        int j = 1;
        while(j<=i){
            char ch  = ('A'+i+j-2);
           cout<< ch << " ";
           ch=ch+1;
           j=j+1;

        }
        cout<<endl;
        i=i+1;

    }
}
*/

/*
int main(){
    int n;
    cin>>n;

    int i=1;
    while(i<=1){
        int space = n-i;
        while(space){
            cout<< " ";
            space = space-1;
        }
        int j=1;
        while(j<-i){
            cout<<'*';
            j=j+1;
        }
    }
}
*/

/*

int main(){
    int n;
    cin>>n;

    int i =1;
    while(i<=n){
        int j=1, space=1;
        while(space<i){
            cout<<" ";
            space=space+1;
        }
        while(j<=n-i+1){
            cout<<"*";
            j=j+1;
        }
        cout<<endl;
        i=i+1;

    }
}
*/

/*

int main(){
    int n;
    cin>>n;

    int i = 1;
    while(i<=n){
        int j=1;
        while(j<=n-i+1){
            cout<<"*";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

/*
int main(){
    int n;
    cin>>n;

    int i =1;
    while(i<=n){
        int j=1, space=1;
        while(space<i){
            cout<<" ";
            space=space+1;
        }
        while(j<=n-i+1){
            cout<< i;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

/*

int main(){
    int n;
    cin>>n;

    int i =1;
    while(i<=n){
        int space=n-i;
        while(space){
            cout<<" ";
            space=space-1;
        }
        int j=1;
        while(j<=i){
            cout<< i;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/
/*
int main(){
    int n;
    cin>>n;

    int i=1;

    while(i<=n){
        int space=n-i;
        while(space){
            cout<<" ";
            space = space-1;
        }

        int j =1;
        while(j<=i){
            cout<<j;
            j=j+1;
        }

        int start=i-1;
        while(start){
            cout<<start;
            start=start-1;
        }
        cout<<endl;
        i=i+1;
    }
    

    }
    
*/

/*

int main(){
    int n;
    cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n-i+1){
            cout<<j<<" ";
            j=j+1;
        }
    
        j=1;
        while(j<=(i-1)*2){
            cout<<"*"<< " ";
            j=j+1;
        }
        j=n-i+1;
        while(j>=1){
            cout<<j<<" ";
            j=j-1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/
