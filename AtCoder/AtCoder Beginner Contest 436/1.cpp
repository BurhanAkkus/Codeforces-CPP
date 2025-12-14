#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;

void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    string o(n - s.length(),'o');
    o+= s;
    cout << o ;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}