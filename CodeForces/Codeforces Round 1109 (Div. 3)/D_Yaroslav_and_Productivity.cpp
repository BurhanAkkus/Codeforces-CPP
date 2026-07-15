#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define MAX_K 25
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

ll a[MAX_N],b[MAX_N];

void solve(){
    ll m,n;
    cin >> n >> m;
    rep(i,0,n,1){
        cin >> a[i];
    }
    rep(i,0,m,1){
        cin >> b[i];
        b[i]--;
    }
    sort(b,b+m);
    b[m] = -1;
    ll iterB = 0;
    ll maxim = 0;
    ll minim = 0;
    rep(i,0,n,1){
        maxim += a[i];
        minim += a[i];
        if(b[iterB] == i){
            iterB++;
            maxim = max(maxim,-minim);
            maxim = max(maxim,-maxim);
            minim = min(minim,-maxim);
            minim = min(-minim,minim);
        }
    }
    cout << maxim << "\n";
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