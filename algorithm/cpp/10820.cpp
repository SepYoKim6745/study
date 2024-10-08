#include <bits/stdc++.h>
using namespace std;
int main() {
    string str;

    while(getline(cin, str)){
        int arr[4];
        fill(arr, arr+4, 0);
        for(char c : str){
            if(c >= 97) arr[0]++;
            else if(c >= '0' && c <= '9') arr[2]++;
            else if(c == ' ') arr[3]++;
            else arr[1]++;
        }
        for(int i : arr) cout << i << ' ';

    }
    return 0;
}