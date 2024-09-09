#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    bool check[1000004] = {false};
    vector<int> prime;
    for(int i = 2; i <= 1000000; i++){
        if(check[i] == false){
            prime.push_back(i);
            for(int j = i+i; j <= 1000000; j+=i){
                check[j] = true;
            }
        }
    }

    int n;

    while(1) {
        cin >> n;
        if(n == 0) break;
        for(int i = 1; i < prime.size(); i++){
            if(check[n-prime[i]] == false){
                cout << n << " = " << prime[i] << " + " << n-prime[i] << '\n';
                break;
            }
        }
    }

    return 0;
}