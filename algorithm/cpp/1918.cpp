#include <bits/stdc++.h>
using namespace std;

int isCheck(char ch) {
    if(ch == '+' || ch == '-') return 1;
    else return 2;
}

int main(){

    string postfix, ret;

    cin >> postfix;

    stack<char> stk;

    for(char c : postfix){
        if(c >= 'A' && c <= 'Z') {
            ret+=c;
        } else if(stk.empty()) {
            stk.push(c);
        } else if(c == '('){
            stk.push(c);
        } else if(c == ')') {
            while(stk.top() != '(') {
                ret += stk.top();
                stk.pop();
            }
            stk.pop();
        } else if(isCheck(c) <= isCheck(stk.top())){
            while(!stk.empty() && isCheck(c) <= isCheck(stk.top()) && stk.top() != '('){
                ret += stk.top();
                stk.pop();
            }
            stk.push(c);
        } else {
            stk.push(c);
        }
    }

    while(!stk.empty()){
        ret+=stk.top();
        stk.pop();
    }

    cout << ret << '\n';


    return 0;
}