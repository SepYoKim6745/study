#include<bits/stdc++.h>
using namespace std;
int main(){

    long long n, m, cnt_two = 0, cnt_five = 0;
    cin >> n >> m;

    for(long long i = 2; i <= n; i*=2){
        cnt_two += n/i;
    }
    
    for(long long i = 2; i <= n-m; i*=2){
        cnt_two -= (n-m)/i;
    }

    for(long long i = 2; i <= m; i*=2){
        cnt_two -= m/i;
    }

    for(long long i = 5; i <=n; i*=5) cnt_five += n/i;
    for(long long i = 5; i <=n-m; i*=5) cnt_five -= (n-m)/i;
    for(long long i = 5; i <=m; i*=5) cnt_five -= m/i;


    cout << min(cnt_two, cnt_five) << '\n';

    return 0;
}