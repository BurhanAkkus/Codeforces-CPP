#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 500;

void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    int inversionCount = 0;
    for(int i = 1; i < n; i++){
        if(s[i] != s[i-1]){
            inversionCount++;
        }
    }
    if(inversionCount == 0){
        cout << 1 << "\n";
        return;
    }
    if(inversionCount == 1){
        cout << 2 << "\n";
        return;
    }
    cout << 1 << "\n";
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
