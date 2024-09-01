#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    char cmd;
    string str;
    cin >> str;
    stack<char> rstk, lstk;
    for(char c : str) lstk.push(c);

    cin >> n;
    while(n--){
        cin >> cmd;
        if(cmd == 'P'){
            char c;
            cin >> c;
            lstk.push(c);
        } else if(cmd == 'B') {
            if(!lstk.empty()) {
                lstk.pop();
            }
        } else if(cmd == 'D') {
            if(!rstk.empty()) {
                lstk.push(rstk.top());
                rstk.pop();
            }
        } else if(cmd == 'L') {
            if(!lstk.empty()) {
                rstk.push(lstk.top());
                lstk.pop();
            }
        }
    }

    while(!lstk.empty()){
        rstk.push(lstk.top());
        lstk.pop();
    }

    while(!rstk.empty()) {
        cout << rstk.top();
        rstk.pop();
    }

    return 0;
}