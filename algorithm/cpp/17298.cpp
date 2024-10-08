#include <bits/stdc++.h>
using namespace std;
int a[1000004];
int nge[1000004];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    stack<int> stk;
    cin >> n;
    // memset(nge, -1, sizeof(nge));
    for(int i = 0; i < n; i++) {
        cin >> a[i+1];

        if(stk.empty()) {
            stk.push(i+1);
        }

        
        while(!stk.empty() && (a[stk.top()] < a[i+1])){
            // cout << stk.top() << '\n';
            nge[stk.top()] = a[i+1];
            stk.pop();
        }
        stk.push(i+1);
    }

    while(!stk.empty()){
        nge[stk.top()] = -1;
        stk.pop();
    }

    for(int i = 1; i <=n; i++){
        cout << nge[i] << ' ';
    }


    return 0;
}