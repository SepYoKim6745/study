#include <bits/stdc++.h>
using namespace std;
int arr1[26], arr2[26];
int cnt;
string str1, str2;
int main(){
   
   cin >> str1;
   cin >> str2;
   
   for(char c : str1){
      arr1[c-97]++;
   }
   
   for(char c : str2){
      arr2[c-97]++;
   }
   
   for(int i = 0; i < 26; i++){
      if(arr1[i] != arr2[i]){
         cnt += abs(arr1[i]-arr2[i]);
      }
   }
   
   cout << cnt;
   
   return 0;
}