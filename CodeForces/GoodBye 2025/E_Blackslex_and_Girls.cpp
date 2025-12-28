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
    ll n;
    cin >> n;
    ll x;
    cin >> x;
    ll xKullandim = 0;
    ll y;
    cin >> y;
    ll yKullandim = 0;
    string s;
    cin >> s;
    vector<ll> p(n);
    ll pSum = 0;
    vector<pair<ll,ll>> votes(n,{0,0});
    for(ll i = 0; i < n; i++){
        cin >> p[i];
        pSum += p[i];
    }
    ll zeroCount =0;
    ll oneCount = 0;
    for(ll i = 0; i < n; i++){
        if(s[i] == '0'){
            zeroCount++;
            votes[i] = {p[i]/2+1,0};
            xKullandim += p[i]/2+1;
        }
    }
    for(ll i = 0; i < n; i++){
        if(s[i] == '1'){
            oneCount++;
            votes[i] = {0,p[i]/2+1};
            yKullandim+= p[i]/2+1;
        }
    }
    if(yKullandim > y || xKullandim > x){
        cout << "NO" << "\n";
        return;
    }
    if(pSum > x+y){
        cout << "NO" << "\n";
        return;
    }
    if(pSum == x+y){
        cout << "YES" << "\n";
        return;
    }
    // pSum < x+y
    if( zeroCount > 0 && oneCount > 0){
        cout << "YES" << "\n";
        return;
    }
    if(zeroCount == 0){
        if(x > y-n){
            cout << "NO" << "\n";
            return;
        }
        cout << "YES" << "\n";
        return;
    }
    if(y > x-n){
        cout << "NO" << "\n";
        return;
    }
    cout << "YES" << "\n";

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
