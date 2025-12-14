#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 500000;


void add(int i,int amount,vector<int>& fenwickTree){
    while(i < fenwickTree.size()){
        fenwickTree[i] += amount;
        i += i & -i;
    }
    return;
}

ll getPrefixSum(int right,const vector<int>& fenwickTree){
    ll sum = 0;
    while(right != 0){
        sum += fenwickTree[right];
        right -= right & -right;
    }
    return sum;
}

ll getIntervalSum(int left, int right,const vector<int>& fenwickTree){
    return getPrefixSum(right, fenwickTree) - getPrefixSum(left,fenwickTree);
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> permutation(n+1);
    
    vector<int> fenwickTree(2*MAX_N+1,0);
    for(ll i = 1; i <= n; i++){
        cin >> permutation[i];
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ll leftKucukler = getPrefixSum(permutation[i],fenwickTree);
        ll rightKucukler = permutation[i] - 1 - leftKucukler;
        ans += (leftKucukler + 1) * (rightKucukler + 1);
        add(permutation[i],1,fenwickTree);
    }
    cout << ans;



}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}