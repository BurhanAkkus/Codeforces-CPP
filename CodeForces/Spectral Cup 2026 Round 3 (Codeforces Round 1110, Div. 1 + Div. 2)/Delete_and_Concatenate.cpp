#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

ll a[MAX_N];

vector<ll> lessThanC;

void solve(){
    ll n,c;
    cin >> n >> c;
    lessThanC.clear();
    ll ans = 0;
    rep(i,0,n,1){
        cin >> a[i];
        if(a[i] < c){
            lessThanC.push_back(a[i]);
        }
    }
    sort(lessThanC.begin(), lessThanC.end(), greater<ll>()); 
    ll zeroCount = n - lessThanC.size();
    ll opCount = 0;
    if(zeroCount >= lessThanC.size()){
        opCount = zeroCount;
    }
    else{
        opCount = zeroCount;
        ll kalan = (lessThanC.size() - zeroCount);
        opCount += (kalan + 1) /2;
    }
    sort(a,a+n, greater<ll>());
    rep(i,0,opCount,1){
        ans += a[i] - c;
    }
    cout << ans << "\n";
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
