#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;

void solve(){
    ll n;
    cin >> n;
    ll furthestRightToFall = 1;
    for(ll i = 1; i <= n; i++){
        ll domino;
        cin >> domino;
        if(i <= furthestRightToFall) furthestRightToFall = max(furthestRightToFall,i+domino - 1);
    }
    cout << min(n,furthestRightToFall) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}