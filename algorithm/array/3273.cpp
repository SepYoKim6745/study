#include <bits/stdc++.h>
using namespace std;
int n, x, cnt;
int arr[1000004];
int check[2000004];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> x;
    for(int i =0; i< n; i++) {
        if(x-arr[i] > 0 && check[x-arr[i]]) cnt++;
        check[arr[i]] = true;
        // cout << x-arr[i] << '\n';
    }
    
    cout << cnt << '\n';

    return 0;
}