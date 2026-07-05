#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;



void solve(){
    ll x,y,k;
    cin >> x >> y >> k;
    vector<ll> xKs;
    while(x > 0){
        xKs.push_back(x);
        x /= k;
    }
    xKs.push_back(0);
    ll c = 0;
    while(y >= 0){
        if(find(xKs.begin(),xKs.end(),y) != xKs.end()){
            cout << find(xKs.begin(),xKs.end(),y) - xKs.begin() + c << "\n";
            return;
        }
        y /= k;
        c++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while(t--){
    solve();
    }
}