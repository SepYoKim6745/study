#include <bits/stdc++.h>
using namespace std;
int tc;
string str;
int main(){

    cin >> tc;
    while(tc) {
        list<char> lk;
        cin >> str;

        list<char>::iterator cursor = lk.begin();

        for(char c : str){
            if(c == '>') {
                if(lk.size() == 0) continue;
                if(cursor == lk.end()) continue;
                cursor++;

            } else if(c == '<') {
                if(lk.size() == 0) continue;
                if(cursor == lk.begin()) continue;
                cursor--;
            } else if(c == '-'){
                if(lk.size() == 0) continue;
                if(cursor == lk.begin()) continue;
                cursor = lk.erase(--cursor);
            } else {
                lk.insert(cursor, c);
            }
        }

        for(char i : lk) {
            cout << i;
        }
        cout << '\n';
        tc--;

    }

    return 0;
}