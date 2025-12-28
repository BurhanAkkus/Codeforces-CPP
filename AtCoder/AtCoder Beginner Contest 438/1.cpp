#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;

void solve(){
    ll d;
    cin >> d;
    ll f;
    cin >> f;
    while( f <= d){
        f += 7;
    }
    cout << f-d;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}