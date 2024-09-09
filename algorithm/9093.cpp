#include <bits/stdc++.h>
using namespace std;
int main(){

    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        string str;
        stack<char> stk;
        getline(cin, str);
        str+='\n';
        for(char c : str) {
            if(c == ' ' || c == '\n') {
                while(!stk.empty()) {
                    cout << stk.top();
                    stk.pop();
                }
                cout << c;
            }
            else {
                stk.push(c);
            }
        }
    }

    return 0;
}