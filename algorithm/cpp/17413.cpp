/*
내가 푼 풀이
#include <bits/stdc++.h>
using namespace std;
string ret;
int main(){

    string str;
    bool flag = false;
    stack<char> stk;


    getline(cin, str);
    str+='\n';
    
    for(char c : str) {
        if(c == '<') flag = true;
        else if(c == '>') {
            ret += c;
            flag = false;
            continue;
        }

        if(flag && stk.empty()){
            ret += c;
        } else {
            if(c == ' ' || c == '\n' || c == '<') {
                while(!stk.empty()) {
                    ret += stk.top();
                    stk.pop();
                }
                if(c == '<') ret += '<';
                else ret += ' ';
            } else {
                stk.push(c);
            }
        }
    }

    // while(!stk.empty()){
    //     ret += stk.top();
    //     stk.pop();
    // }
    cout << ret;

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

void print(stack<char> &s) {
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
}

int main() {

    string str;
    getline(cin, str);
    bool tag = false;
    stack<char> s;

    for(char c : str) {
        if(c == '<') {
            print(s);
            tag = true;
            cout << c;
        } else if(c == '>') {
            tag = false;
            cout << c;
        } else if(tag) {
            cout << c;
        } else {
            if(c == ' ') {
                print(s);
                cout << c;
            } else {
                s.push(c);
            }
        }
    }

    print(s);
    cout << '\n';

    return 0;
}