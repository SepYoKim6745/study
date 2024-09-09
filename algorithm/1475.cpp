#include <bits/stdc++.h>
using namespace std;
int arr[10];
int ret;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    
    cin >> n;

    while(n) {
        arr[n%10]++;
        n /= 10;
    }

    for(int i = 0; i <= 9; i++) {
        if(i == 6 || i == 9) continue;
        ret = max(ret, arr[i]);
    }

    int tmp = (arr[6] + arr[9]);
    ret = max(ret, (tmp/2) + (tmp%2));
    cout << ret;
    
    return 0;
}