#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 5000;
vector<ll> numberArray(MAX_N+5,-1);
vector<ll> numberArrayIndices(MAX_N+5,-1);


void solve(){
    char a;
    cin >> a;
    if(a >= 'a' && a <= 'z'){
        cout <<'a';
        return;
    }
    cout <<'A';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
