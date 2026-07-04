#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX

const ll MAX_N = 200000;
vector<vector<ll>> edges(MAX_N+1);
vector<ll> subtreeVertexCount(MAX_N + 1);
vector<ll> subtreeKareCount(MAX_N + 1);
ll totalVertexCount;
vector<ll> kareler;
vector<ll> a(MAX_N + 1);


bool checkSquare(ll i){
    int sq = sqrt(i);
    return sq * sq == i;
}

ll calculateSubtreeVertexCount(int root, int parent){
    ll count = 0;
    for(ll child:edges[root]){
        if(parent == child){
            continue;
        }
        count += calculateSubtreeVertexCount(child,root);
    }
    subtreeVertexCount[root] = count + 1;
    return count + 1;
}

ll calculateSubtreeKareCount(int root, int parent){
    ll count = 0;
    for(ll child:edges[root]){
        if(parent == child){
            continue;
        }
        count += calculateSubtreeKareCount(child,root);
    }
    if(checkSquare(a[root])){
        count++;
    }
    subtreeKareCount[root] = count;
    return count;
}


ll combinationThree(ll n){
    if(n < 3){
        return 0;
    }
    return n * (n-1) * (n-2) / 6;
}

ll combinationTwo(ll n){
    if(n < 2){
        return 0;
    }
    return (n * n - n) /2;
}

ll calculateAnswer(int root, ll parent){
    if(!checkSquare(a[root])){
        ll count = 0;
        for(ll child:edges[root]){
            if(child == parent){
                continue;
            }
            count += calculateAnswer(child,root);
        } 
        return count;
    }
    ll childScores = 0;
    ll benimSubtree = subtreeVertexCount[root];
    ll a = combinationTwo(benimSubtree - 1);
    ll b = combinationThree(benimSubtree - 1);
    for(ll child:edges[root]){
        if(parent == child)
        {
            continue;
        }
        childScores += calculateAnswer(child,root);
        a -= combinationTwo(subtreeVertexCount[child]);
        b -= combinationThree(subtreeVertexCount[child]);
        b -= combinationTwo(subtreeVertexCount[child]) * (benimSubtree - subtreeVertexCount[child] - 1);
    }
    ll x1 = a;
    ll x2 = b;
    ll x3 = (benimSubtree - 1) * (totalVertexCount - benimSubtree);
    ll x4 = a * (totalVertexCount - benimSubtree);
    return x1 + x2 + x3 + x4 + childScores;
}

void solve(){
    ll n;
    cin >> n;
    totalVertexCount = n;
    for(int i = 0; i <= n; i++){
        edges[i].clear();
        subtreeVertexCount[i] = 0;
        if(i == 0){
            continue;
        }
        ll sayi;
        cin >> sayi;
        a[i] = sayi;
        if(checkSquare(sayi)){
            kareler.push_back(i);
        }
    }    

    for(int i = 0; i < n-1; i++){
        ll u,v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    // root = 1;
    if(kareler.size() == 0){
        cout << 0 << "\n";
        return;
    }
    ll root = kareler[0];
    calculateSubtreeVertexCount(root,root);
    cout << calculateAnswer(root,root) << "\n";


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
