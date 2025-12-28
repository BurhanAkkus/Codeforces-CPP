#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 5000;
vector<ll> numberArray(MAX_N+5,-1);
vector<ll> numberArrayIndices(MAX_N+5,-1);

bool isInversion(ll a, ll b){
    return a > b;
}

void solve(){
    string s;
    cin >> s;
    ll ans = s[0] == 's'? 0 : 1;
    s[0] = 's';
    for(ll i = 1; i < s.length();i++){
        if(s[i] == 'u' && s[i-1] == 'u'){
            ans++;
            s[i] = 's';
        }
    } 
    if(s[s.length()-1] == 'u'){
        ans++;
    }
    cout << ans<<"\n";
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
