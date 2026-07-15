#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define MAX_K 25
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<vector<ll>,MAX_N> children;
array<ll,MAX_N> minLeafs,maxLeafs,a;

bool leavesAreOrderable(ll root){
    // if root has no children
    if(children[root].size() == 0){
        if(a[root] == 0){
            minLeafs[root] = -1;
            maxLeafs[root] = -1;
            return true;
        }
        minLeafs[root] = a[root];
        maxLeafs[root] = a[root];
        return true;
    }
    ll minLeaf = Infinity;
    ll minLeafChild = -1;
    vector<ll>& cc = children[root];
    rep(i,0,cc.size(),1){
        if(!leavesAreOrderable(cc[i])){
            return false;
        }
        if(minLeafs[cc[i]] != -1){
            if(minLeafs[cc[i]] < minLeaf){
                minLeaf = minLeafs[cc[i]];
                minLeafChild = i;
            }
        }
    }

    if(minLeafChild == -1){
        minLeafs[root] = -1;
        maxLeafs[root] = -1;
        return true;
    }
    ll maxLeaf = maxLeafs[cc[minLeafChild]];
    rep(i,minLeafChild+1,cc.size(),1){
        if(minLeafs[cc[i]] == -1){
            continue;
        }
        if(minLeafs[cc[i]] != maxLeaf + 1){
            return false;
        }
        maxLeaf = maxLeafs[cc[i]];
    }
    rep(i,0,minLeafChild,1){
         if(minLeafs[cc[i]] == -1){
            continue;
        }
        if(minLeafs[cc[i]] != maxLeaf + 1){
            return false;
        }
        maxLeaf = maxLeafs[cc[i]];
    }
    minLeafs[root] = minLeaf;
    maxLeafs[root] = maxLeaf;
    return true;
}

void solve(){
    ll n;
    cin >> n;
    rep(i,0,n+3,1){
        children[i].clear();
    }
    rep(i,1,n,1){
        ll p;
        cin >> p;
        children[p].push_back(i+1);
    }
    rep(i,0,n,1){
        cin >> a[i + 1];
    }
    if(leavesAreOrderable(1)){
        cout << "YES\n";
        return;
    }
    cout <<"NO\n";

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
