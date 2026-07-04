#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 500;

void solve(){
    ll x;
    cin >> x;
    ll y = 1;
    while(x > 0){
        y *=10;
        x /= 10;
    }
    cout <<y + 1 << "\n";
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
