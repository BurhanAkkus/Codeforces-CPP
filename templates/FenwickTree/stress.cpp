#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// ---- generator bounds (tune here) ----
const ll  VAL   = 1000000000LL; // max |x|
const int CAP_N = 200;          // upper bound on n for "normal" cases
const int CAP_Q = 400;          // upper bound on q

// ============================================================
//  YOUR SOLUTION: implement the Fenwick tree in this struct.
//  (Same logic you'd put in sol.cpp, just as functions.)
//  Leave the bodies as TODO and fill them yourself.
// ============================================================
struct Fenwick {
    int n;
    // TODO: your storage (e.g. vector<ll> bit;)
    void init(int n_)          { n = n_; /* TODO */ }
    void update(int i, ll x)   { /* TODO: add x at 0-indexed i */ (void)i; (void)x; }
    ll   range(int l, int r)   { /* TODO: sum of 0-indexed [l,r] */ (void)l; (void)r; return 0; }
};

// ============================================================
//  Brute oracle: literal definition. Obviously correct.
// ============================================================
struct Brute {
    int n; vector<ll> a;
    void init(int n_)        { n = n_; a.assign(n, 0); }
    void update(int i, ll x) { a[i] += x; }
    ll   range(int l, int r) { ll s = 0; for (int j = l; j <= r; j++) s += a[j]; return s; }
};

// ============================================================
//  Reproducible case generator: same seed -> same case.
// ============================================================
struct Op { int t; int a; ll b; };   // t=1 -> (i,x) ; t=2 -> (l,r)
struct Case { int n; vector<Op> ops; };

Case genCase(uint64_t seed){
    mt19937_64 rng(seed);
    auto rnd = [&](ll lo, ll hi){ return lo + (ll)(rng() % (uint64_t)(hi - lo + 1)); };

    int nmode = (int)(rng() % 10);          // ~30% land on tiny n
    int n;
    if      (nmode == 0) n = 1;
    else if (nmode <= 2) n = (int)rnd(2, 5);
    else                 n = (int)rnd(1, CAP_N);

    int q     = (int)rnd(1, CAP_Q);
    int vmode = (int)(rng() % 4);           // 0 random,1 all-equal,2 max-bound,3 tiny
    ll  fixedx = rnd(-VAL, VAL);

    Case c; c.n = n; c.ops.reserve(q);
    for (int k = 0; k < q; k++){
        int t = (int)(rng() % 2) + 1;
        if (t == 1){
            int i = (int)rnd(0, n - 1); ll x;
            if      (vmode == 1) x = fixedx;
            else if (vmode == 2) x = (rng() & 1) ? VAL : -VAL;
            else if (vmode == 3) x = rnd(-5, 5);
            else                 x = rnd(-VAL, VAL);
            c.ops.push_back({1, i, x});
        } else {
            int l = (int)rnd(0, n - 1), r = (int)rnd(0, n - 1);
            if (l > r) swap(l, r);
            c.ops.push_back({2, l, (ll)r});
        }
    }
    return c;
}

// Reprint a failing case in the exact problem I/O format, so you can paste it
// straight into your standalone sol.cpp for debugging.
void printCase(const Case& c){
    fprintf(stderr, "%d %d\n", c.n, (int)c.ops.size());
    for (const Op& o : c.ops){
        if (o.t == 1) fprintf(stderr, "1 %d %lld\n", o.a, o.b);
        else          fprintf(stderr, "2 %d %d\n",  o.a, (int)o.b);
    }
}

int main(int argc, char** argv){
    long long T      = (argc > 1) ? atoll(argv[1])              : 100000; // # test cases
    uint64_t  base   = (argc > 2) ? strtoull(argv[2], nullptr, 10) : 1;   // base seed

    for (long long tc = 0; tc < T; tc++){
        uint64_t seed = base + (uint64_t)tc;
        Case c = genCase(seed);

        Fenwick fw; fw.init(c.n);
        Brute   bf; bf.init(c.n);

        for (size_t k = 0; k < c.ops.size(); k++){
            const Op& o = c.ops[k];
            if (o.t == 1){
                fw.update(o.a, o.b);
                bf.update(o.a, o.b);
            } else {
                int l = o.a, r = (int)o.b;
                ll got = fw.range(l, r);
                ll exp = bf.range(l, r);
                if (got != exp){
                    fprintf(stderr,
                        "MISMATCH  seed=%llu  op#%zu  query [%d,%d]  got=%lld expected=%lld\n",
                        (unsigned long long)seed, k, l, r, got, exp);
                    fprintf(stderr, "--- failing case ---\n");
                    printCase(c);
                    return 1;
                }
            }
        }
    }
    printf("ALL %lld CASES PASSED\n", T);
    return 0;
}
