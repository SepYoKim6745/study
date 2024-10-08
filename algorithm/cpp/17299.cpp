#include <bits/stdc++.h>
using namespace std;
int freq[1000004];
int main(){

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> ret(n);
    stack<int> stk;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        freq[a[i]]++;
    }

    for(int i = 0; i < n; i++){
        if(stk.empty()){
            stk.push(i);
        }
        
        while(!stk.empty() && freq[a[stk.top()]] < freq[a[i]]){
            ret[stk.top()] = a[i];
            stk.pop();
        }

        stk.push(i);
    }

    while(!stk.empty()){
        ret[stk.top()] = -1;
        stk.pop();
    }

    for(int i = 0; i < n; i++){
        cout << ret[i] << ' ';
    }

    return 0;
}