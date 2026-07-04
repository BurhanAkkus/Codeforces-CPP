#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 500;

bool cakes[MAX_N + 1];
bool belirsiz[MAX_N + 1];
void solve(){
    ll n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cakes[i] = false;
        belirsiz[i] = false;
        char c;
        cin >> c;
        if(c == 'T'){
            cakes[i] = true;
        }
        if(c == 'F'){
            cakes[i] = false;
        }
        if(c == 'N'){
            belirsiz[i] = true;
        }
    }
    
    
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
