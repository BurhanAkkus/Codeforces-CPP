#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;

vector<ll> permutation(static_cast<size_t>(MAX_N) + 5);
vector<pair<int,int>> edges(static_cast<size_t>(MAX_N) + 5);
vector<pair<ll,ll>> minMaxes(static_cast<size_t>(MAX_N) + 5);

void solve(){
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> permutation[i];
    }
    ll curMax = permutation[n-1];
    ll curMin = permutation[n-1];
    size_t usedPermutation = 0;
    size_t usedEdges = 0;
    size_t usedMinMaxes = 0;
    for(ll i = n - 2; i >= 0; i--){
        if(permutation[i] > curMax){
            minMaxes[usedMinMaxes++] = {curMin, curMax};
            curMin = permutation[i];
            curMax = permutation[i];
        }
        else{
            edges[usedEdges++] = {permutation[i], curMax};
            curMin = min(curMin, permutation[i]);
        }
    }
    minMaxes[usedMinMaxes++] = {curMin, curMax};
    ll currentMin = minMaxes[usedMinMaxes -1].first;
    for(ll i = usedMinMaxes -1; i >=0; i--){
        if(minMaxes[i].second < currentMin){
            cout << "No" << "\n";
            return;
        }
        else{
            edges[usedEdges++] = {currentMin, minMaxes[i].second};
        }
        currentMin = min(currentMin, minMaxes[i].first);
    }
    cout << "Yes" << "\n";
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