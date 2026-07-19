#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200005;
const long long MAX_M = 2;
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

ll n,m;
ll a[MAX_N],b[MAX_N],c[MAX_N];
void solve(){
    cin >> n >> m;
    rep(i,0,n,1){
        cin >> a[i];
    }
    rep(i,0,n-1,1){
        cin >> b[i];
    }
    ll lastA = a[0];
    ll ans = 0;
    
    rep(i,1,n,1){
        c[i-1] = (b[i-1] - lastA - a[i] + 3*m) %m;
        lastA = a[i] + c[i-1];
        lastA %=m;
        ans += c[i-1];
    }
    
    priority_queue<pair<ll,bool>,vector<pair<ll,bool>>, greater<pair<ll,bool>>> pq;
    rep(i,0,n-1,1){
        if(i%2 == 1){
            c[i] = m-c[i];
        }
        pq.push({c[i],i%2});
    }
    ll running = 0;
    ll minAns = ans;
    while(!pq.empty()){
        auto [kalan,type] = pq.top();
        pq.pop();
        ans += (n%2) * (kalan - running);
        running = kalan;
        ll artanCounter = 0;
        ll azalanCounter = 0;

        if(type){
            artanCounter++;
        }
        else{
            azalanCounter++;
        }
        while(!pq.empty() && pq.top().first == kalan){
            auto [next,nextType] = pq.top();
            pq.pop();
            if(nextType){
                artanCounter++;
            }
            else{
                azalanCounter++;
            }
        }
        ans -= artanCounter * m;
        minAns = min(minAns,ans);
        ans += azalanCounter * m;
    }
    cout << minAns;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}