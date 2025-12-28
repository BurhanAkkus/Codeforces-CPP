#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;

void solve(){
    ll n;
    cin >> n;
    vector<ll> numbers(n+1);
    for( ll i = 0; i < n; i++){
        cin >> numbers[i];
    }
    stack<pair<ll,ll>> s;
    for(ll i = 0; i < n ; i++){
        if(s.size() > 0){
            pair<ll,ll> top = s.top();
            if(top.first == numbers[i]){
                s.pop();
                if(top.second != 3){
                    s.push({top.first,top.second+1});
                }
            }
            else{
                s.push({numbers[i],1});
            }
        }
        else{
            s.push({numbers[i],1});
        }
    }
    ll ans = 0;
    while(s.size() > 0){
        ans += s.top().second;
        s.pop();
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}