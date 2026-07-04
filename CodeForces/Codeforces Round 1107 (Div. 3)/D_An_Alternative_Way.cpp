#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 500;
vector<ll> a;
vector<ll> b;
void solve(){
    ll n;
    cin >> n;
    a.clear();
    b.clear();
    for(int i = 0; i < n; i++){
        ll sayi;
        cin >> sayi;
        a.push_back(sayi);
    }
    for(int i = 0; i < n; i++){
        ll sayi;
        cin >> sayi;
        b.push_back(sayi);
    }
    for(int i = n-1; i > 0; i--){
        if(a[i] > b[i]){
            a[i-1] += a[i] - b[i];
        }
    }
    if(a[0] <= b[0]){
        cout <<"YES" << "\n";
        return;
    }
    cout << "NO" << "\n";

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
