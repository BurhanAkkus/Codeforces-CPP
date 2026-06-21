#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;

void solve(){
    ll n;
    cin >> n;
    vector<pair<ll,ll>> takahashi(n);
    for(int i = 0; i < n; i++){
        ll height, time;
        cin >> height >> time;
        takahashi[i] = {height, time};
    }
    sort(takahashi.begin(), takahashi.end(), [](const pair<ll,ll>& a, const pair<ll,ll>& b){
        return a.second > b.second ? true : (a.second == b.second ? a.first > b.first : false);
    });
    vector<pair<ll,ll>> maxes;
    
    maxes.push_back({takahashi[0].second, -1});
    ll current_max = takahashi[0].first;
    for(int i = 1; i < n; i++){
        // if last max has height more than the current chech, changhe the time.
        if(current_max < takahashi[i].first){
            maxes.push_back({takahashi[i].second,current_max});
            current_max = takahashi[i].first;
        }
    }
    maxes.push_back({0,current_max});

    ll q;
    cin >> q;
    for(int i = 0; i < q; i++){
        ll t;
        cin >> t;
        // the first of maxes that has a first <= t
        auto it = lower_bound(maxes.begin(), maxes.end(), make_pair(t, 0LL), [](const pair<ll,ll>& a, const pair<ll,ll>& b){
            return a.first > b.first;
        });
        if(it == maxes.end()){
            cout << -1 << endl;
        }
        else{
            cout << it->second << endl;
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}