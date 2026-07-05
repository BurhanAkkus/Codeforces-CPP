#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;

void solve(){
    ll x,y,l,r,a,b;
    cin >> x >> y >> l >> r >> a >> b;
    if( a >= r || b <= l){
        cout << (b-a) * y<< "\n";
        return;
    }
    if(a >=l && b <= r){
        cout << (b-a) * x << "\n";
        return;
    }
    if(a < l && b > r){
        cout << (l-a) * y + (r-l) * x + (b-r) * y << "\n";
        return;
    }
    ll leftBound = max(a,l);
    ll rightBound = min(b,r);
    cout << (leftBound - a) * y + (rightBound - leftBound) * x + (b - rightBound) * y << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}