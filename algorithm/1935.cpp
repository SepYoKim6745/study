#include <bits/stdc++.h>
using namespace std;
int operand[30];
double ret;
int main() {
    
    int n;
    string postfix;

    cin >> n;
    cin >> postfix;

    for(int i = 0; i < n; i++){
        cin >> operand[i];
    }

    stack<double> stk;

    for(char ch : postfix) {
        if(ch >= 'A' && ch <= 'Z') {
            stk.push((double)operand[ch-65]);
        } else {
            double op1 = stk.top(); stk.pop();
            double op2 = stk.top(); stk.pop();
            
            if(ch == '+') stk.push(op1+op2);
            if(ch == '-') stk.push(op2-op1);
            if(ch == '/') stk.push(op2/op1);
            if(ch == '*') stk.push(op1*op2);
        }
    }

    cout << fixed << setprecision(2) << stk.top() << '\n';

    return 0;
}