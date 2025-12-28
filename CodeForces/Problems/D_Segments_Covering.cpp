#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define MOD 998244353
#define Infinity LONG_LONG_MAX
const long long MAX_N = 2e5;

long long mod_pow(long long a, long long e) {
    long long r = 1 % MOD;
    a %= MOD;
    while (e > 0) {
        if (e & 1) r = (__int128)r * a % MOD;
        a = (__int128)a * a % MOD;
        e >>= 1;
    }
    return r;
}

long long mod_inv(long long y) {
    // mod must be prime, and y % mod != 0
    return mod_pow(y, MOD - 2);
}

vector<ll> l(MAX_N + 5);
vector<ll> r(MAX_N + 5);
vector<ll> p(MAX_N + 5);
vector<ll> q(MAX_N + 5);

struct Node{
    int node_left;
    int node_right;
    ll c = 1;
    ll b = 0;
};

// push segment tree

vector<Node> segmentTree(MAX_N * 4 + 5);

void buildSegmentTree(int nodeIndex,int left, int right){
    segmentTree[nodeIndex].node_left = left;
    segmentTree[nodeIndex].node_right = right;
    if(left != right){
        buildSegmentTree(nodeIndex << 1,left,(left+right)/2);
        buildSegmentTree(nodeIndex << 1 |1,(left+right)/2 + 1,right);
    }    
}


void degisimUygula(Node& n,ll p,ll q){
    ll modInvQ = mod_inv(q);
    ll scale   = (q - p) % MOD * modInvQ % MOD;   // (q-p)/q
    ll add     = ((p % MOD) * modInvQ) % MOD;       // p/q

    n.b = (n.b * scale % MOD + n.c * add % MOD) % MOD;
    n.c = (n.c * scale) % MOD;
    return;
}

void pushDown(int nodeIndex){
    Node& n = segmentTree[nodeIndex];
    if( (n.c == 1 && n.b == 0) || n.node_left == n.node_right){
        return;
    }
    else{
        Node& leftChild = segmentTree[nodeIndex<<1];
        Node& rightChild = segmentTree[nodeIndex<<1|1];
        leftChild.b = (leftChild.b * n.c) % MOD + (leftChild.c * n.b) % MOD;
        leftChild.b %= MOD;
        leftChild.c *= n.c;
        leftChild.c %= MOD;
        rightChild.b = (rightChild.b * n.c) % MOD + (rightChild.c * n.b) % MOD;
        rightChild.b %= MOD;
        rightChild.c *= n.c;
        rightChild.c %= MOD;
        n.c = 1;
        n.b = 0;
    }
}

void update(int nodeIndex, int l, int r, ll p, ll q){
    Node& n = segmentTree[nodeIndex];
    
    // node tamamen intervalin disindaysa
    if( n.node_left > r || n.node_right < l){
        return;
    }
    // node tamamen  intervalin icindeyse
    if(n.node_left >= l && n.node_right <= r){
        degisimUygula(n,p,q);
        return;
    }
    // node kismen icerdeyse
    // icindeki degisimi asagiya pushla
    // asagidakilerden devam et.
    pushDown(nodeIndex);
    update(nodeIndex<<1,l,r,p,q);
    update(nodeIndex<<1 | 1,l,r,p,q);
}
void solve(){
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    buildSegmentTree(1,1,m);
    ll l,r,p,q;
    for(ll i = 0; i < n; i++){
        cin >> l >> r >> p >> q;
        update(1,l,r,p,q); 
    }
    for(ll i = 1; i <= 4*m; i++){
        pushDown(i);
    }
    ll sum = 1;
    for(ll i = 1; i <= 4*m; i++){
        if(segmentTree[i].node_left == segmentTree[i].node_right && segmentTree[i].node_left != 0){
        sum *= segmentTree[i].b;
        sum %= MOD;
        }
    }
    cout << sum;

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t=1;
    while(t--){
        solve();
    }
}
