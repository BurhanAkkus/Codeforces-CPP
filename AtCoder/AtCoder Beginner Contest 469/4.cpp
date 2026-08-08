#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

vector<pair<ll,ll>> finals;

// index of the first final that neither x nor y reached, -1 if they cover everything
ll firstUncovered(ll x, ll y){
    rep(i,0,(ll)finals.size(),1){
        auto [f1,f2] = finals[i];
        if(f1 != x && f2 != x && f1 != y && f2 != y) return i;
    }
    return -1;
}

void solve(){
    ll n,m;
    cin >> n >> m;
    finals.resize(m);
    rep(i,0,m,1) cin >> finals[i].first >> finals[i].second;

    if(m == 0){
        cout << n*(n-1)/2 << "\n";
        return;
    }

    // every valid pair must contain an endpoint of the first final
    ll a = finals[0].first, b = finals[0].second;

    // players who cover every final on their own: any partner works for them
    vector<ll> alone;
    if(firstUncovered(a,a) == -1) alone.push_back(a);
    if(firstUncovered(b,b) == -1) alone.push_back(b);

    if(alone.size() == 2){
        cout << 2*n - 3 << "\n";
        return;
    }

    ll ans = 0;
    if(alone.size() == 1) ans += n - 1;

    set<pair<ll,ll>> found;
    for(ll x : {a,b}){
        if(!alone.empty() && x == alone[0]) continue;
        ll idx = firstUncovered(x,x);            
        for(ll y : {finals[idx].first, finals[idx].second}){
            if(y == x) continue;
            if(!alone.empty() && y == alone[0]) continue;
            if(firstUncovered(x,y) == -1) found.insert({min(x,y), max(x,y)});
        }
    }
    ans += (ll)found.size();

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
