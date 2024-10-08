#include <bits/stdc++.h>
using namespace std;
list<char> lk;
int n, m;
string str;
char order, x;
int main(){
    cin >> str;

    for(int i = 0; i < str.length(); i++){
        lk.push_back(str[i]);
    }
    list<char>::iterator cursor = lk.end();
    
    cin >> m;

    for(int i = 0; i < m; i++) {
        cin >> order;
        if(order == 'P'){
            cin >> x;
            lk.insert(cursor, x);
        } else if(order == 'L'){
            if(cursor == lk.begin()) continue;
            cursor--;
        } else if(order == 'D') {
            if(cursor == lk.end()) continue;
            cursor++;
        } else {
            if(cursor == lk.begin()) continue;
            cursor--;
            cursor = lk.erase(cursor);
        }
    }

    for(auto c : lk) {
        cout << c;
    }

    return 0;
}