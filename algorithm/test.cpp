#include <bits/stdc++.h>
using namespace std;
int bitCount(int x) {
    if(x == 0) return 0;
    return x % 2 + bitCount(x / 2);
}
int main(){
    cout << __builtin_popcount(10);
    return 0;
}