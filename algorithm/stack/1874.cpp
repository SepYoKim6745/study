#include <bits/stdc++.h>
using namespace std;
int n, j = 1;
stack<int> stk;
int arr[100004];
string ret;
int main(){

    cin >> n;
    
    for(int i = 1; i < n; i++){
        cin >> arr[i];
    }

    int i;

    for(i = 1; i <= n; i++){
        while(j < i){
            stk.push(i);
            ret += "+\n";
        }
        if(stk.top() == arr[j]) {
            stk.pop();
            ret += "-\n";
            j++;
        }
    }

    cout << ret;

    return 0;
}