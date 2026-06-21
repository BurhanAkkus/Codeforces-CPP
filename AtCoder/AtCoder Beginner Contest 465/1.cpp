#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;

void solve(){
    ll x;
    cin >> x;
    ll y;
    cin >> y;
    if(x * 9 == y * 16){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}