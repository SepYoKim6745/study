#include <bits/stdc++.h>
using namespace std;
list<int> arr, ret;
int n, k, cnt = 1;
int main(){

    cin >> n >> k;
    
    for(int i = 1; i <= n; i++){
        arr.push_back(i);
    }

    list<int>::iterator cur = arr.begin();

    while(ret.size() != n) {
        if(cnt % k == 0){
            ret.push_back(*cur);
            cur = arr.erase(cur);
            if(cur == arr.end()) cur = arr.begin();
        } else {
            cur++;
            if(cur == arr.end()) cur = arr.begin();
        }
        cnt++;
    }
    int i = 0;
    cur = ret.begin();
    cout << "<";
    while(i < ret.size()-1) {
        cout << *cur++;
        cout << ", ";
        i++;
    }
    cout << *cur << ">";

    return 0;
}