#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 200002
#define MAX_N2 20002
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#include <cassert>
#include <iostream>
using namespace std;

ll arr[MAX_N]{};

void update(int i,int x){
    int leastSignificantBit = __builtin_ctz(i);
    while(i < MAX_N){
        arr[i] += x;
        leastSignificantBit = __builtin_ctz(i);
        i += 1 << leastSignificantBit;
    }
}

ll prefixSum(int i){
    ll sum = 0;
    int leastSignificantBit = __builtin_ctz(i);
    while(i){
        sum += arr[i];
        i -= 1 << leastSignificantBit;
        leastSignificantBit = __builtin_ctz(i);
    }
    return sum;
}

void solve(){
    ll n,q;
    cin >> n >> q;
    rep(i,0,n+1,1){
        arr[i] = 0;
    }
    rep(i,0,q,1){
        ll type,index,x;
        cin >> type >> index >> x;
        index++;
        if(type == 1){
            update(index,x);
        }
        if(type == 2){
            x++;
            cout << prefixSum(x) - prefixSum(index -1) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--){
    solve();
    }
}
