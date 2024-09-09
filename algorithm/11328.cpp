#include<bits/stdc++.h>
using namespace std;
int tc;
string a, b;
int main(){
   
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   
   cin >> tc;
   
   while(tc--) {
      bool ret = false;
      int arr1[26];
      fill(arr1, arr1+26, 0);
      
      cin >> a >> b;
      
      for(char c : a) arr1[c-97]++;
      for(char c : b) arr1[c-97]--;
      
      for(int i = 0; i < 26; i++){
         if(arr1[i]) ret = true;
      }
      if(ret) cout << "Impossible" << '\n';
      else cout << "Possible" << '\n';
   }
   
   
   return 0;
}