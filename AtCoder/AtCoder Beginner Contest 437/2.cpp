#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 100;

void solve(){
    ll h;
    cin >> h;
    ll w;
    cin >> w;
    ll n;
    cin >>n;
    map<ll,ll> numberRow;
    vector<bool> present(MAX_N,false);
    vector<ll> rowScores(h+1,0);
    ll num;
    for(ll i = 0 ; i < h; i++){
        for(ll j = 0; j < w; j++){
            cin >> num;
            numberRow[num] = i; 
            present[num] = true;
        }
    }
    for(int i = 0 ; i < n; i++){
        cin >> num;
        if(!present[num]) continue;
        rowScores[numberRow[num]]++;
    }
    ll max = 0;
    for(ll i = 0 ; i < h; i++){
        if(rowScores[i] > max){
            max = rowScores[i];
        }
    }
    cout << max << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}