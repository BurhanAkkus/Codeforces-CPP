#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;

ll nChoosek( ll n, ll k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}


void solve(){
    ll n;
    cin >> n;
    
    vector<vector<ll>> points(n,vector<ll>(n));
    if(  n %2 == 0){
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                // yarisina kadar 1 sonrasi 0
                if(j < n/2){
                    points[i][j] = 1;
                }else{
                    points[i][j] = 0;
                }
            }
        }
    }
    else{
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                // yarisina kadar 1 sonrasi 0
                if(j <= n/2 && i !=0){
                    points[i][j] = 1;
                }else{
                    points[i][j] = 0;
                }
            }
        }
        points[0][0] = 1;
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cout << points[i][j];
        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}