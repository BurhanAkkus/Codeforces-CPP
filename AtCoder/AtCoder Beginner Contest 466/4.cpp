#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 300005;
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

ll rows[MAX_N],columns[MAX_N];

void solve(){
    ll n,m;
    cin >> n >> m;
    rep(i,0,m,1){
        ll r,c;
        cin >> r >> c;
        if(rows[r] != 0){
            columns[rows[r]] = 0;
        }
        if(columns[c] != 0){
            rows[columns[c]] = 0;
        }
        rows[r] = c;
        columns[c] = r; 
    }
    ll ans = 0;
    rep(i,0,n + 1,1){
        ans += (rows[i] > 0) & 1;
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}