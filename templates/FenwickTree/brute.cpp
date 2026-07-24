#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Correct by construction: literal definition of the ops, with a fresh array
// per test case (point-add mutates one cell; range-sum re-adds every cell in [l,r]).
int main(){
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--){
        int n, q; scanf("%d %d", &n, &q);
        vector<ll> a(n, 0);
        while (q--){
            int t; scanf("%d", &t);
            if (t == 1){
                int i; ll x; scanf("%d %lld", &i, &x);
                a[i] += x;
            } else {
                int l, r; scanf("%d %d", &l, &r);
                ll s = 0;
                for (int j = l; j <= r; j++) s += a[j];
                printf("%lld\n", s);
            }
        }
    }
    return 0;
}
