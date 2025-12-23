#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;

ll nChoosek( ll n, ll k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}


void solve(){
    ll n;
    cin >> n;
    vector<vector<char>> points(n,vector<char>(n));
    vector<pair<ll,ll>> ones;
    vector<pair<ll,ll>> zeroes;

    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin >> points[i][j];
            if(points[i][j]=='1'){
                ones.push_back({i,j});
            }else{
                zeroes.push_back({i,j});
            }
        }
    }
    set<pair<ll,ll>> oneWays;
    set<pair<ll,ll>> zeroWays;
    for(auto [x1,y1]:ones){
        for(auto [x2,y2]:ones){
            ll dx = x2 - x1;
            ll dy = y2 - y1;
            if(dx >= 0 && dy >= 0)
            oneWays.insert({dx,dy});
        }
    }
    for(auto [x1,y1]:zeroes){
        for(auto [x2,y2]:zeroes){
            ll dx = x2 - x1;
            ll dy = y2 - y1;
            if(dx >= 0 && dy >= 0){
                zeroWays.insert({dx,dy});
            }
        }

    }
    ll diff = 0;
    for(auto [dx,dy]:oneWays){
        if(zeroWays.find({dx,dy})==zeroWays.end()){
            diff+= nChoosek(dx+dy,dy);
        }
    }
    for(auto [dx,dy]:zeroWays){
        if(oneWays.find({dx,dy})==oneWays.end()){
            diff-= nChoosek(dx+dy,dy);
        }
    }
    cout << diff << "\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}