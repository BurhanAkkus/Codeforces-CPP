#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define Infinity LONG_LONG_MAX
#define MOD 998244353
const long long MAX_N = 200000;

//Segment tree
// each node is 2 values, x,y
// the tree holds 4 values as aggregation operation
// max(x+y),max(x-y), when there is an equality in these 2, max x is taken
// min(x+y),min(x-y), when there is an equality in these 2, max y is taken
struct SegmentTree {
    struct Node {
        ll max_sum, max_diff, min_sum, min_diff;
    };
    
    vector<Node> tree;
    ll n;
    
    SegmentTree(ll size) : n(size), tree(4 * size) {}
    
    Node merge(Node a, Node b) {
        Node result;
        result.max_sum = max(a.max_sum, b.max_sum);
        result.max_diff = max(a.max_diff, b.max_diff);
        result.min_sum = min(a.min_sum, b.min_sum);
        result.min_diff = min(a.min_diff, b.min_diff);
        return result;
    }
    
    void update(ll idx, ll x, ll y, ll node = 0, ll start = 0, ll end = -1) {
        if(end == -1) end = n - 1;
        if(start == end) {
            tree[node] = {x + y, y-x, x+y ,y-x};
            return;
        }
        ll mid = (start + end) / 2;
        if(idx <= mid) update(idx, x, y, 2 * node + 1, start, mid);
        else update(idx, x, y, 2 * node + 2, mid + 1, end);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }
    
    Node query(ll l, ll r, ll node = 0, ll start = 0, ll end = -1) {
        if(end == -1) end = n - 1;
        if(l > end || r < start) return {-Infinity, -Infinity, Infinity, Infinity};
        if(l <= start && end <= r) return tree[node];
        ll mid = (start + end) / 2;
        return merge(query(l, r, 2 * node + 1, start, mid), 
                     query(l, r, 2 * node + 2, mid + 1, end));
    }
    // generate function to create the tree from a vector of pairs with given size
    void build(const vector<pair<ll, ll>>& values) {
        for(ll i = 0; i < values.size(); i++) {
            update(i, values[i].first, values[i].second);
        }
    }
};



void solve(){
    ll n;
    cin >> n;
    ll q;
    cin >> q;
    vector<pair<ll,ll>> trees(n);
    for(ll i = 0; i < n; i++){
        ll x,y;
        cin >> x >> y;
        trees[i]={x,y};
    }
    SegmentTree segTree(n);
    segTree.build(trees);
    for(ll i = 0; i < q; i++){
        ll type;
        cin >> type;
        if(type==1){
            ll idx,x,y;
            cin >> idx >> x >> y;
            segTree.update(idx-1,x,y);
        }else{
            ll l,r;
            cin >> l >> r;
            ll x,y;
            cin >> x >> y;
            auto result=segTree.query(l-1,r-1);
            ll ans = 0;
            ans = max(ans, abs(result.max_sum - x - y));
            ans = max(ans, abs(result.max_diff - y + x));
            ans = max(ans, abs(result.min_sum - x - y));
            ans = max(ans, abs(result.min_diff - y + x));
            cout << ans << "\n";
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    while(t--)   solve();
}