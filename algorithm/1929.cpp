#include <bits/stdc++.h>
using namespace std;
int main(){

    int start, end;
    cin >> start >> end;

    vector<bool> v(end+1);
    vector<int> ret;

    for(int i = 2; i <= end; i++) {
        if(v[i] == false){
            if(i >= start) ret.push_back(i);
        }

        for(int j = i*2; j <= end; j+=i){
            v[j] = true;
        }
    }

    for(auto i : ret) cout << i << '\n';


    return 0;
}