#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;

void solve(){
    ll n;
    cin >> n;
    //vector n by n
    vector<vector<int>> square(static_cast<size_t>(n), vector<int>(static_cast<size_t>(n), 0));

    ll lastx = 0;
    ll lasty = (n-1) /2;
    ll lastWrittenNumber = 1;
    square[lastx][lasty] = lastWrittenNumber;
    for(ll i = 0; i < n*n -1; i++){
        if( square[(lastx + n - 1) % n][(lasty + n + 1) %n] == 0){
            square[(lastx + n - 1) % n][(lasty + n + 1) %n] = ++lastWrittenNumber;
            lastx = (lastx + n - 1) % n;
            lasty =(lasty + n + 1) %n;
        }
        else{
            square[(lastx + n + 1) % n][(lasty + n) %n] = ++lastWrittenNumber;
            lastx = (lastx + n + 1) % n;
            lasty=(lasty + n) %n;
        }
    }
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            cout << square[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}