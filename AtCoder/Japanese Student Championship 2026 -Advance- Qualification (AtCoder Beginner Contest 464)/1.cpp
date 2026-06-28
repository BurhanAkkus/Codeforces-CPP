#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;

void solve(){
    string s;
    cin >> s;
    int wCount = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'W'){
            wCount++;
        }
    }
    if(wCount > s.length() /2){
        cout << "West" << endl;
        return;
    }
    cout << "East" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}