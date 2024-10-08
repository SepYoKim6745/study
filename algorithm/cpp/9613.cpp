#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}
int main(){
    long long sum;
    long long t, n;
    cin >> t;
    while(t--){
        sum = 0;
        cin >> n;
        vector<long long> num(n);
        
        for(long long i = 0; i < n; i++) cin >> num[i];

        for(long long i = 0; i < n; i++){
            for(long long j = i+1; j < n; j++){
                sum += gcd(num[i], num[j]);
            }
        }
        cout << sum << '\n';
    }

    return 0;
}