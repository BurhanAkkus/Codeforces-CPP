#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 200002
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))


struct dsu
{
    vector<int> parent;
    vector<int> size;
    int n;
    public:
    dsu(int n) :parent(n), size(n, 1),n(n){
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x){
        while(x != parent[x]){
        x = parent[x] = parent[parent[x]];}
        return x;
    }
    int union_(int a,int b){
        if( a >= (int)parent.size() || b >=(int) parent.size() || a < 0 || b < 0){
            return -1;
        }
        a = find(a);
        b = find(b);
        
        if( a == b) return -1;
        if(size[a] < size[b]){
            swap(a,b);
        }
        parent[b] = a;
        size[a] += size[b];
        return b;
    }
    int size_(int a){
        a = find(a);
        return size[a];
    }
};

int main(){


    dsu myDistinctUnion = dsu(10);
    myDistinctUnion.union_(5,4);
    myDistinctUnion.union_(8,9);
    myDistinctUnion.union_(1,4);
    myDistinctUnion.union_(3,6);
    myDistinctUnion.union_(7,8);
    rep(i,0,myDistinctUnion.n,1){
        cout << i << " " << myDistinctUnion.find(i) << " " << myDistinctUnion.size_(i) << "\n";
    }
}
