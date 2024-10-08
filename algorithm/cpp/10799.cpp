#include <bits/stdc++.h>
using namespace std;
int main(){

    string s;
    char prev;
    stack<char> stk;
    int ret = 0;
    cin >> s;
    for(char ch : s) {
        if(ch == '('){
            stk.push(ch);
        } else if(ch == ')' && prev == '('){
            stk.pop();
            ret += stk.size();
        } else {
            stk.pop();
            ret+=1;
        }
        prev = ch;
    }

    cout << ret << '\n';


    return 0;
}