#include <bits/stdc++.h>
using namespace std;
int n;
long long ret;
stack<int> stk;

int main(){
    
    cin >> n;

    while(n) {
        int height;
        cin >> height;
        while(!stk.empty() && stk.top() <= height){
            stk.pop();
        }
        ret += stk.size();
        stk.push(height);
        n--;
    }

    cout << ret;
    return 0;
}