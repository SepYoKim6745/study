#include <bits/stdc++.h>
using namespace std;
int main(){

    int n, sum = 1;
    cin >> n;

    for(int i = 2; i <=n; i++){
        sum *= i;
    }

    cout << sum << '\n';

    return 0;
}