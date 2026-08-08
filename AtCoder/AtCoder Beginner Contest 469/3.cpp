#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 200002
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define Infinity LONG_LONG_MAX

vector<ll> xIndices;

// returns the first element i such that array[i] > element
ll upper_bound_custom(vector<ll>& array, ll n, ll element){
    ll l = 0;
    ll r = n;
    while(l < r){
        ll mid = l + (r - l) /2; // rounds down.
        if(array[mid] <= element) {l = mid + 1;} // shrinks the interval [l,r) 
        else{
            r = mid; // shrinks the interval.
        }
    }
    return l;
}

void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    rep(i,0,n,1){
        if(s[i] == 'x'){
            xIndices.push_back(i + 1);
        }
    }
    rep(k,1,n+1,1){
        ll xSayim = upper_bound_custom(xIndices,xIndices.size(),k);
        ll oSayim = k - xSayim;
        if(xIndices.size() < oSayim + xSayim){
            cout << n << "\n";
            continue;
        }
        cout << xIndices[oSayim + xSayim - 1] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    // cin >> t;
    while(t--){   
        solve();
    }
}