#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 200002
#define MAX_K 25
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#include <cassert>
#include <iostream>
using namespace std;

array<ll,MAX_N> a;

vector<ll> palindrome1,palindrome2,palindrome3;
ll mex(vector<ll>& includes){
    sort(includes.begin(),includes.end());
    ll mex = 0;
    int iter = 0;
    while(iter < includes.size() && includes[iter++] == mex){
        mex++;
    }
    return mex;
}

void solve(){
    ll n;
    cin >> n;
    int zeroIndex1 = -1, zeroIndex2 = -1;
    rep(i,0,n*2,1){
        cin >> a[i];
        if(a[i] == 0){
            if(zeroIndex1 == -1){
                zeroIndex1 = i;
            }
            else{
                zeroIndex2 = i;
            }
        }
    }

    ll maxMex = -1;
    // Center is zeroIndex1
    int radius = 0;
    palindrome1.clear();
    while(zeroIndex1 - radius >= 0 && zeroIndex1 + radius < 2*n && a[zeroIndex1 - radius] == a[zeroIndex1 + radius]){
        palindrome1.push_back(a[zeroIndex1-radius]);
        radius++;
    }
    maxMex = max(maxMex,mex(palindrome1));
    // Center is zeroIndex2
    radius = 0;
    palindrome2.clear();
    while(zeroIndex2 - radius >= 0 && zeroIndex2 + radius < 2*n && a[zeroIndex2 - radius] == a[zeroIndex2 + radius]){
        palindrome2.push_back(a[zeroIndex2-radius]);
        radius++;
    }
    maxMex = max(maxMex,mex(palindrome2));
    // Center is middle
    int middle = zeroIndex1 + (zeroIndex2 - zeroIndex1) / 2;
    palindrome3.clear();
    radius = 0;
    int offset  = ((zeroIndex2 - zeroIndex1) % 2 == 0) ? 0 : 1;
    while(middle - radius >= 0 && middle + offset + radius < 2*n && a[middle - radius] == a[middle + offset + radius]){
        palindrome3.push_back(a[middle-radius]);
        radius++;
    }
    maxMex = max(maxMex,mex(palindrome3));

    cout << maxMex << "\n";
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
