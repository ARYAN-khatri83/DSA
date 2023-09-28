vector<int> printNos(int x) {
    // Write Your Code Here
vector<int> a;
  
    if(x==0)
    {
        return a;
    }
    else
    { 
        a=printNos(x-1);
 
         a.push_back(x);
    }
    
 
}
