#include <bits/stdc++.h>
using namespace std;
string ret;
int main(){

    int n, num, i = 1;
    cin >> n;
    stack<int> stk;

    while(n) {
        cin >> num;
        
        while(i <= num) {
            stk.push(i);
            ret += "+\n";
            i++;
        }
        if(stk.top() == num){
            while(!stk.empty() && stk.top() == num) {
                stk.pop();
                ret += "-\n";
            }
        } else {
            ret = "NO";
            break;
        }
        n--;
    }
    
    cout << ret;

    return 0;
}