    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    #define MAX_N 200002
    #define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
    #define Infinity LONG_LONG_MAX


    array<ll,105> a;
    void solve(){
        ll n,k;
        cin >> n >> k;
        cout << n + 1 - k;
    }

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        ll t = 1;
        // cin >> t;
        while(t--){   
            solve();
        }
    }