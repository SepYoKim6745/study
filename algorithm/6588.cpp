#include <bits/stdc++.h>
using namespace std;
int main(){
    
    bool check[1000004];
    vector<int> ret;

    for(int i = 2; i <= 1000000; i+=1){
        if(check[i] == false){
            ret.push_back(i);
        }

        for(int j = i*2; j <= 1000000; j+=i){
            check[j] = true;
        }
    }

    int n;

    while(1){
        cin >> n;
        if(n == 0) break;
        for(int i = 1; i < ret.size(); i++){
            if(!check[n-ret[i]]){
                cout << n << " = " << ret[i] << " + " << n-ret[i] << '\n';
                break;
            }
        }
    }
    return 0;
}