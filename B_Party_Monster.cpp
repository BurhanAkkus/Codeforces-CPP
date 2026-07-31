#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 200002
#define MAX_K 25
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#include <cassert>
#include <iostream>
using namespace std;

void solve(){
    ll n;
    cin >> n;
    ll count1 = 0;
    ll count2 = 0;
    rep(i,0,n,1){
        char c;
        cin >> c;
        if(c == '('){
            count1++;
        }
        else{
            count2++;
        }
    }
    if(count1 == count2){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}
