// #include <bits/stdc++.h>
// using namespace std;
// int n, height;
// stack<pair<int, int>> stk;
// vector<int> ret;
// int main(){

//     cin >> n;

//     for(int i = 0; i < n; i++) {
//         cin >> height;

//         while(!stk.empty() && stk.top().first < height) {
//             stk.pop();
//         }

//         if(!stk.empty())
//             ret.push_back(stk.top().second);
//         else
//             ret.push_back(0);

//         stk.push({height, i+1});
//     }

//     for(auto i : ret) {
//         cout << i << ' ';
//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n;
stack<pair<int, int>> tower;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    tower.push({100000001, 0 });

    for(int i = 1; i <= n; i++){
        int height;
        cin >> height;
        while(tower.top().X < height)
            tower.pop();
        
        cout << tower.top().Y << ' ';
        tower.push({height, i});
    }

}