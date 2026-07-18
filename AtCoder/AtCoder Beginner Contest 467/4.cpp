#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 300005;
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))



void solve(){
    ll px,py,qx,qy,rx,ry,sx,sy;
    cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;

    // paralel ve farkli dogrularsa kesismez.
    ll deltaX1 = qx - px;
    ll deltaY1 = qy - py;
    ll deltaX2 = sx - rx;
    ll deltaY2 = sy - ry;

    // lines are parallel
    if(deltaX1 * deltaY2 == deltaX2 * deltaY1){
        // same line or not?
        ll mx = (rx + sx) - (px + qx); 
        ll my = (ry + sy) - (py + qy);
        cout << (deltaX1 * mx + deltaY1 * my == 0 ? "Yes\n" : "No\n");
        return;
    }
    cout << "Yes\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}