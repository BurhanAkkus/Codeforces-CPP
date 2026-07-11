#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MOD 998244353
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define repRev(i,start,end,decrement) for(ll i=(start);i>(end);i-=(decrement))

ll l,r,n;

ll powersOfTwo[64];

void populatePowersOfTwo(){
    powersOfTwo[0] = 1;
    rep(i,1,40,1){
        powersOfTwo[i] = 2 * powersOfTwo[i - 1];
    }
}

// returns the first element i such that 2**i > r_
ll lower_bound_custom(ll r_){
    // answer lies [l,r), r is excluded.
    ll l = 0;
    ll r = 40;
    while(l < r){
        ll mid = l + (r - l) /2; // rounds down.
        // answer can't be in mid.
        if(powersOfTwo[mid] <= r_) {l = mid + 1;} // shrinks the interval [l,r)
        else{
            r = mid; // shrinks the interval.
        }
    }
    return l;
}

string findSolutionString(ll x,ll y){
    // binary string of x
    string s = "";

    // binarize x
    while(x > 0){
        s = char(x%2 + '0') + s;
        x /= 2;
    }

    while(s.size() < n){
        s += s;
    }

    //binary string of y
    string p = "";
    while(y > 0){
        p = char(y % 2 + '0') + p;
        y /=2;
    }

    while(p.size() < n){
        p += p;
    }
    string cevap = "";
    rep(i,0,n,1){
        cevap += (s[i] - '0' & p[i] - '0') + '0';
    }

    return cevap;
}

void solve(){
    cin >> l >> r >> n;

    //find largest i such that 2**i <= r
    ll i = lower_bound_custom(r) - 1;
    if(powersOfTwo[i] >= l){
        if(powersOfTwo[i-1] >= l){
            // x = 2**i, y = 2 ** (i-1)
            cout << findSolutionString(powersOfTwo[i], powersOfTwo[i-1]) << "\n";
            return;
        }
        else{
            // x = r, y = 2**i or x = 2**i, y = l
            string cevap1 = findSolutionString(r,powersOfTwo[i]);
            string cevap2 = findSolutionString(powersOfTwo[i],l);
            // find the lexicographically smaller one.
            cout <<min(cevap1, cevap2) << "\n";
            return;
        }
    }
    else{
        // 2 ** i < l < r
        ll B = lower_bound_custom(r); // first i with 2^i > r == bitlen(r)
        string period(B, '0');
        rep(j,0,B,1){
            ll bit = B - 1 - j;
            ll rb = (r >> bit) & 1;
            ll lb = (l >> bit) & 1;
            if(rb != lb) break;              // from here down not all k agree
            period[j] = char('0' + rb);      // agree -> keep the common bit
        }
        string cevap = "";
        while((ll)cevap.size() < n){
            cevap += period;
        }
        rep(i,0,n,1){
            cout<<cevap[i];
        }
        cout <<"\n";
        return;
    }


}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    populatePowersOfTwo();
    cin >> t;
    while(t--){
        solve();
    }
}
