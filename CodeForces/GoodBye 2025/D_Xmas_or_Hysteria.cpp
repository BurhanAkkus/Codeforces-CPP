#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 2e5;

vector<ll> nums(MAX_N + 5);
void solve(){
    ll n;
    cin >>n;
    ll m;
    cin >> m;
    for(ll i = 0;i < n; i++){
        cin >> nums[i];
    }
    if( 2*m > n){
        cout << "-1\n";
        return;
    }
    vector<ll> indices(n);
    iota(indices.begin(), indices.end(), 0);
    // sort indices.
    sort(indices.begin(), indices.end(), [&](ll a, ll b) {
        return nums[a] < nums[b];
    });

    if(m == 0){
        ll max = nums[indices[n-1]];
        ll iter = n-2;
        while(max > 0 && iter >=0){
            max -= nums[indices[iter--]];
        }
        if(max > 0){
            cout << "-1\n";
            return;
        }
        iter++;
        cout<< n-1 << "\n";
        for(ll i = 0; i < iter; i++){
            cout << indices[i] +1 << " " << indices[i+1]+1 <<"\n";
        }
        for(ll i = iter; i < n-1; i++){
            cout << indices[i] +1<< " " << indices[n-1]+1 <<"\n";
        }
    }
    else
    {
        cout << n-m << "\n";
        ll i = 0;
        for(; i < n-2*m; i++){
            cout << indices[i]+1 << " " << indices[i+1]+1 << "\n";
        }
        for(ll j = 0; j < m ; j++){
            cout << indices[n-1-j]+1 << " " << indices[i++]+1 << "\n";
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
