#include <bits/stdc++.h>
using namespace std;
int main(){

    string str;
    vector<string> ret;

    cin >> str;
    for(int i = 0; i < str.length(); i++){
        ret.push_back(str.substr(i, str.length()-i));
    }

    sort(ret.begin(), ret.end());
    for(auto a : ret){
        cout << a << '\n';
    }

    return 0;
}