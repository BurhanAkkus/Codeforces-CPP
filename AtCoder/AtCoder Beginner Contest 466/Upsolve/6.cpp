#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define MAX_K 25
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))


void solve(){
    ll n ,x;
    cin >> n >> x;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>> pq;

    pq.push({x,1});
    ll min = Infinity;
    rep(i,0,n,1){
        ll a;
        cin >> a;
        if(a < min){
            while(!pq.empty()){
                auto [m,count] = pq.top();
                if(m < a){
                    break;
                }
                pq.pop();
                while(!pq.empty() && pq.top().first == m){
                    count += pq.top().second;
                    pq.pop();
                }
                pq.push({a-1,m/a * count});
                pq.push({m%a,count});
            }
            min = a;
        }
    }
    ll ans = 0;
    while(!pq.empty()){
        auto [m,count] = pq.top();
        pq.pop();
        ans += count;
    }
    cout << ans - 1 << "\n";
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