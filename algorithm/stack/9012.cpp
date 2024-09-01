#include <bits/stdc++.h>
using namespace std;
int main(){

    int t;
    cin >> t;
    while(t--) {
        string str, ret = "YES";
        cin >> str;
        stack<char> stk;
        for(char ch : str) {
            if(ch == '(') {
                stk.push(ch);
            } else {
                if(stk.empty()) {
                    ret = "NO";
                    break;
                } else {
                    stk.pop();
                }
            }
        }
        if(!stk.empty()) ret = "NO";
        cout << ret << '\n';
    }

    return 0;
}