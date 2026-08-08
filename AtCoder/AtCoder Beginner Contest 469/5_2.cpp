#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX_N 1000005
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

ll n,k;
string s;


array<ll,MAX_N> winCountPrefix;
array<double,MAX_N> probabilityPrefix;
bool solvableForP(double p){
    winCountPrefix[0] = s[0] == 'o';
    rep(i,1,n,1){
        winCountPrefix[i] = winCountPrefix[i-1] + (s[i] == 'o');
    }
    double oProb{1-p},xProb{p};
    probabilityPrefix[0] = (s[0] == 'o') * oProb - (s[0] == 'x') * xProb;
    rep(i,1,n,1){
        probabilityPrefix[i] = probabilityPrefix[i-1] + (s[i] == 'o') * oProb - (s[i] == 'x') * xProb;
    }
    size_t l{0};
    double currentMin = 0;
    rep(r,0,n,1){
        while(winCountPrefix[r] - k >= (l > 0? winCountPrefix[l-1] : 0)){
            currentMin = min(currentMin,l > 0 ? probabilityPrefix[l - 1] : 0);
            l++;
            if(probabilityPrefix[r] - currentMin > 0) return true;
        }
    }
    return false;
}


double lower_bound_custom(double lowerBound,double upperBound){
    // answer lies [l,r]
    double l = lowerBound;
    double r = upperBound;
    while(l + 0.0000001 < r){
        double mid = l + (r - l) /2; // rounds down.
        // answer can't be in mid.
        if(solvableForP(mid)) {l = mid + 0.0000001;} // shrinks the interval [l,r] 
        else{
            r = mid; // shrinks the interval.
        }
    }
    return l;
}


void solve(){
    cin >> n >> k;
    cin >> s;

    cout << fixed << setprecision(8) <<  lower_bound_custom(0.0,1.0) - 0.0000001;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
