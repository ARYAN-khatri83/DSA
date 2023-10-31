#include <bits/stdc++.h> 
using namespace std;

void deleteMiddle(stack<int> &inputStack, int n) {
   if(n == 1) {
      inputStack.pop();
      return;
   }

   vector<int> temp;
   while(!inputStack.empty()) {
      temp.push_back(inputStack.top());
      inputStack.pop();
   }

   int ind = (n + 1) % 2 == 0 ? ((n + 1) / 2) - 1 : (n + 1) / 2;
   for(int i = ind; i < temp.size() - 1; i++)
      temp[i] = temp[i + 1];
   
   temp.pop_back();

   for(int i = temp.size() - 1; i >= 0; i--)
      inputStack.push(temp[i]);
}
