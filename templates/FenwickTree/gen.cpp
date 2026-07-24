#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// ---- generator bounds (tune here) ----
const ll  VAL   = 1000000000LL; // max |x|
const int CAP_N = 200;          // upper bound on n for "normal" cases
const int CAP_Q = 400;          // upper bound on q

// Emit ONE case, fully determined by `seed` (so it can be reproduced in isolation).
void emitCase(uint64_t seed){
    mt19937_64 rng(seed);
    auto rnd = [&](ll lo, ll hi){ return lo + (ll)(rng() % (uint64_t)(hi - lo + 1)); };

    int nmode = (int)(rng() % 10);           // ~30% tiny n
    int n;
    if      (nmode == 0) n = 1;
    else if (nmode <= 2) n = (int)rnd(2, 5);
    else                 n = (int)rnd(1, CAP_N);

    int q     = (int)rnd(1, CAP_Q);
    int vmode = (int)(rng() % 4);            // 0 random,1 all-equal,2 max-bound,3 tiny
    ll  fixedx = rnd(-VAL, VAL);

    printf("%d %d\n", n, q);
    for (int k = 0; k < q; k++){
        int t = (int)(rng() % 2) + 1;
        if (t == 1){
            int i = (int)rnd(0, n - 1); ll x;
            if      (vmode == 1) x = fixedx;
            else if (vmode == 2) x = (rng() & 1) ? VAL : -VAL;
            else if (vmode == 3) x = rnd(-5, 5);
            else                 x = rnd(-VAL, VAL);
            printf("1 %d %lld\n", i, x);
        } else {
            int l = (int)rnd(0, n - 1), r = (int)rnd(0, n - 1);
            if (l > r) swap(l, r);
            printf("2 %d %d\n", l, r);
        }
    }
}

// argv[1] = base seed, argv[2] = T (cases), argv[3] = first case index (default 0).
// Case c uses seed = base + first + c, so `gen base 1 c` reproduces case c alone.
int main(int argc, char** argv){
    uint64_t  base  = (argc > 1) ? strtoull(argv[1], nullptr, 10) : 0ULL;
    long long T     = (argc > 2) ? atoll(argv[2]) : 1000;
    long long first = (argc > 3) ? atoll(argv[3]) : 0;

    printf("%lld\n", T);
    for (long long c = 0; c < T; c++)
        emitCase(base + (uint64_t)first + (uint64_t)c);
    return 0;
}
