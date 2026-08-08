#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 500005
#define MAX_K 25
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<ll,MAX_N> p,pInverse;
array<bool,MAX_N> used;

// segment tree
struct SegmentTree{
    int size;
    vector<ll> array;
    public:
    SegmentTree(int n):size(n),array(n*4,0){};
    void insert(int node, int l, int r,int targetIndex,ll element){
        if(l == r && l == targetIndex){
            array[node] = element;
            return;
        }
        if(targetIndex < l || targetIndex > r){
            return;
        }
        insert(node*2,l,l+(r-l)/2,targetIndex,element);
        insert(node*2+1,l+(r-l)/2+1,r,targetIndex,element);
        array[node] = max(array[node*2],array[node*2+1]);
        return;
    }
    ll rangeQuery(int node,int l, int r, int qL,int qR){
        if(qL > r || qR < l){
            return 0;
        }
        if(qL <= l && qR >= r){
            return array[node];
        }
        return max(rangeQuery(node*2,l,l + (r-l)/2,qL,qR),
                    rangeQuery(node*2+1,l + (r-l)/2 + 1, r,qL,qR));
    }
};

void solve(){
    ll n;
    cin >> n;
    rep(i,0,n,1){
        cin >> p[i];
        pInverse[p[i]] = i + 1;
        used[i] = false;
    }
    ll c = 0;
    ll max = -1;
    rep(i,0,n,1){
        if(max < p[i]){
            max = p[i];
            used[p[i]] = true;
            c++;
        }
    }
    SegmentTree st(n);
    for(int i = n; i > 0; i--){
        if(!used[i]){
            int targetIndex = pInverse[i];
            ll maxim = st.rangeQuery(1,1,n,targetIndex+1,n);
            st.insert(1,1,n,targetIndex,maxim+1);
        }
    }
    c += st.rangeQuery(1,1,n,1,n);
    cout << c;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    //cin >> t;
    while(t--){
        solve();
    }
}