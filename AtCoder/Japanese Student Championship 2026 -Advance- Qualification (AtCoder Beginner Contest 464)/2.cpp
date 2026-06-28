#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;

char harita[55][55];
void solve(){
    ll h,w;
    cin >> h >> w;

    ll minB = 100,maxB= 0,leftB = 10000,rightB =0;
    for(ll i = 0; i < h; i++){
        for(ll j = 0; j < w; j++){
            char c;
            cin >> harita[i][j];
            c = harita[i][j];
            if(c == '#'){
                minB = min(minB,i);
                maxB = max(maxB,i);
                leftB = min(leftB,j);
                rightB = max(rightB,j);
            }
        }
    }
    for(ll i = minB; i <= maxB; i++){
        for(ll j = leftB; j <= rightB;j++){
            cout << harita[i][j];
        }
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}