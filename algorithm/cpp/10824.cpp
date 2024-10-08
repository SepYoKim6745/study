#include <bits/stdc++.h>
using namespace std;
int main(){

    string a, b, c, d;

    cin >> a >> b >> c >> d;

    unsigned long long op1 = stol(a+b);
    unsigned long long op2 = stol(c+d);
    unsigned long long ret = op1 + op2;
    cout << ret << '\n';

    return 0;
}