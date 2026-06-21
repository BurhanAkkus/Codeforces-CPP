#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;

void solve(){
    ll n;
    cin >> n;
    char x;
    cin >> x;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    int target = x - 'A';
    for(int  i = 0; i < n; i++){
        if(s[i][target] == 'o'){
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}