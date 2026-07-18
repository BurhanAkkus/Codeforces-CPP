#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define MAX_K 25
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))


void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,0,n,1){
        cin >> a[i];
    }
    if(n %2 == 1){
        cout << "NO\n";
        return;
    }
    ll plusCount = 0;
    rep(i,0,n,1){
        if(a[i] == 1){
            plusCount++;
        }
    }
    ll minusCount = n - plusCount;
    if(abs(minusCount - plusCount) %4 == 0){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}