#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i < n-1; i++){
        if(n % i == 0) return false;
    }
    return true;
}
int main(){

    int n;
    int cnt = 0 ;

    cin >> n;
    vector<int> v(n);
    
    for(int i = 0; i < n; i++)
        cin >> v[i];

    for(auto i : v){
        if(isPrime(i)) cnt++;
    }

    cout << cnt;


    return 0;
}