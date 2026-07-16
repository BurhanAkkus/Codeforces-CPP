#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

vector<ll> stack_;
bool used[MAX_N];
void solve(){
    ll n,k;
    cin >> n >> k;
    stack_.clear();
    rep(i,0,n,1){
        used[i] = false;
    }
    ll target = n ^ k;
    ll current;
    do{
        current = 0;
        // MSB = 63 when target = 0.
        int msb = 63 - __builtin_clzll(target);
        rep(i,0,msb + 1,1){
            if((1<<(msb - i)) & target && (current + (1<<(msb - i)) ) < n) current +=(1<<(msb - i));
        }
        stack_.push_back(current);
        used[current] = true;
        target ^= current;
    }while(current != 0);
    if(stack_.size() > n || target != 0){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    rep(i,1,n,1){
            if(!used[i]){
                cout << i << " ";
            }
        }
    rep(i,0,stack_.size(),1){
        cout << stack_[stack_.size() -1 -i] << " ";
    }
    cout << "\n";
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
