#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;

void solve(){
    ll n;
    cin >> n;
    vector<ll> permutation(n);
    for(ll i = 0; i< n; i++){
        cin >> permutation[i];
        permutation[i]--;
    }
    vector<set<ll>> loops;
    for(ll i = 0; i < n; i++){
        if(permutation[i] == -1){
            continue;
        }
        else{
            set<ll> newLoop;
            newLoop.insert(i);
            ll nextElement = permutation[i];
            permutation[i] = -1;
            while(!newLoop.contains(nextElement)){
                newLoop.insert(nextElement);
                ll previousElement = nextElement;
                nextElement = permutation[nextElement];
                permutation[previousElement] = -1;
            }
            loops.push_back(newLoop);
        }
    }
    ll ans = 0;
    for(auto currentSet:loops){
        ans += (currentSet.size() * currentSet.size() - currentSet.size()) /2;
    }
    cout<< ans;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}