#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MOD   998244353
const long long MAX_N = 200000;

void solve(){
    ll n;
    cin >> n;
    vector<int> numbers(n,0);
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }
    vector<ll> costs(n,0);
    for(ll i = 0; i < n; i++){
        cin >> costs[i];
    }
    map<ll,ll> dpResult;
    for(int i = 0; i < n; i++){
        ll currentCost = costs[i];
        auto it = dpResult.upper_bound(numbers[i]); 
        if(it != dpResult.begin()){
            --it;                      
            currentCost += it->second;
        }
        dpResult[numbers[i]] = currentCost;
        for(auto it2 = dpResult.upper_bound(numbers[i]); it2 != dpResult.end();){
            if(it2->second > currentCost) break;
            it2 = dpResult.erase(it2);
        }
    }
    ll costsSum = accumulate(costs.begin(),costs.end(),0LL);
    ll dpMax = -1;
    for(auto it2 = dpResult.begin(); it2 != dpResult.end();it2++){
        dpMax = max(it2->second,dpMax);
        }
    cout << costsSum - dpMax << "\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}
