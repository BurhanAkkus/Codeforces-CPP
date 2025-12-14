#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
const long long MAX_N = 200000;

// Segment tree that supports range update (set to 1) and range sum queries on 0/1 data.
struct SegmentTree {
    int n;
    vector<ll>tree;
    vector<bool>lazy;

    void init(int size) {
        n = 1;
        while(n < size) n <<= 1;
        tree.assign(2*n, 0);
        lazy.assign(2*n, false);
    }
    SegmentTree(int size) {
        init(size);
    }

    // set range [l, r] to 1
    void apply_set(int node, int l,int r){
        tree[node] = (r-l+1);
        lazy[node <<1] = true;
        lazy[node <<1 | 1] = true;
        lazy[node] = false;
        return;
    }
    void push(int node, int l, int r){
        if(lazy[node]){
            apply_set(node, l, r);
        }
    }
    void set_range(int currentNode,int currentNodeLeft, int currentNodeRight, int   queryLeft,int queryRight){
        // if t here was something waiting, push it dowm.
        push(currentNode, currentNodeLeft, currentNodeRight);
        // no overlap
        if(currentNodeLeft > queryRight || currentNodeRight < queryLeft) return;
        // total overlap
        if(queryLeft <= currentNodeLeft && currentNodeRight <= queryRight){
            apply_set(currentNode, currentNodeLeft, currentNodeRight);
            return;
        }
        // partial overlap
        int mid = (currentNodeLeft + currentNodeRight) >> 1;
        set_range(currentNode << 1, currentNodeLeft, mid, queryLeft, queryRight);
        set_range(currentNode << 1 | 1, mid + 1, currentNodeRight, queryLeft, queryRight);
        tree[currentNode] = tree[currentNode << 1] + tree[currentNode << 1 | 1]; 
    }
    void set_range(int l, int r){
        set_range(1, 0, n - 1, l, r);
    }
    ll querySum(int currentNode, int currentNodeLeft, int currentNodeRight, int queryLeft, int queryRight){
        // if there was something waiting, push it dowm.
        push(currentNode, currentNodeLeft, currentNodeRight);
        // no overlap
        if(currentNodeLeft > queryRight || currentNodeRight < queryLeft) return 0;
        // total overlap
        if(queryLeft <= currentNodeLeft && currentNodeRight <= queryRight){
            return tree[currentNode];
        }
        // partial overlap
        int mid = (currentNodeLeft + currentNodeRight) >> 1;
        return querySum(currentNode << 1, currentNodeLeft, mid, queryLeft, queryRight) +
               querySum(currentNode << 1 | 1, mid + 1, currentNodeRight, queryLeft, queryRight);
    }
};

void solve(){
    ll n;
    cin >> n;
    ll q;
    cin >> q;
    SegmentTree segTree(n);
    for(ll i = 0; i < q; i++){
        ll a,b;
        cin >> a >> b;
        segTree.set_range(a-1,b-1);
        cout << n - segTree.query_sum(0,n-1) << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}