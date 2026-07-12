#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 200002
#define MAX_N2 20002
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#include <cassert>
#include <iostream>

array<vector<int>,MAX_N> edges;
array<int,MAX_N> parent;
array<ll,MAX_N> subTreeSizes;

ll subTreeSize(int root){
    ll subTree = 1;
    for(auto& child: edges[root]){
        if(parent[root] != child){
            subTree += subTreeSize(child);
        }
    }
    subTreeSizes[root] = subTree;
    return subTree;
}

int main(){

    
}
