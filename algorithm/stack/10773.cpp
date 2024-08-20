#include <bits/stdc++.h>
using namespace std;
int k, n, sum;
stack<int> stk;
int main(){
   
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   cin >> k;
   
   while(k--){
      cin >> n;
      if(n == 0) stk.pop();
      else stk.push(n);
   }
   
   while(stk.size()){
      sum += stk.top();
      stk.pop();
   }
   
   cout << sum;
   
   return 0;
}