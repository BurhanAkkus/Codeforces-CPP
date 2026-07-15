// gen.cpp
// Random test generator for the "difference array" problem.
// Usage: gen.exe <seed>
// Emits: line 1 "n q", then q lines "l r x".
#include <bits/stdc++.h>
using namespace std;

// ---- problem bounds (constants up top) ----
static const int N_MAX = 200000;
static const int Q_MAX = 200000;
static const long long X_MAX = 1000000000LL; // |x| <= 1e9

// Caps used for the "general" / "max-bound-values" modes so the O(n*q)
// brute-force oracle stays fast across thousands of stress iterations.
// True boundary sizes (N_MAX/Q_MAX) belong in a separate one-off max test,
// not in the tight stress loop.
static const int GEN_N_CAP = 2000;
static const int GEN_Q_CAP = 2000;

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <seed>\n", argv[0]);
        return 1;
    }
    unsigned long long seed = strtoull(argv[1], nullptr, 10);
    mt19937_64 rng(seed);

    auto randInt = [&](long long lo, long long hi) -> long long {
        uniform_int_distribution<long long> d(lo, hi);
        return d(rng);
    };

    int mode = (int)randInt(0, 99);
    int n, q;
    bool maxBoundValues = false;
    bool allEqual = false;
    bool forceLastAtN = false; // force the final query's r to n-1

    if (mode < 25) {
        // 25%: small-n bias so any failure is tiny and readable
        n = (int)randInt(2, 5);
        q = (int)randInt(1, 10);
    } else if (mode < 33) {
        // n = 1 degenerate
        n = 1;
        q = (int)randInt(1, 5);
    } else if (mode < 37) {
        // absolute minimal valid input
        n = 1;
        q = 1;
    } else if (mode < 47) {
        // all-equal: every update spans the whole array, so the result
        // is a single repeated value across all indices
        n = (int)randInt(1, 50);
        q = (int)randInt(1, 10);
        allEqual = true;
    } else if (mode < 62) {
        // max-bound values: x pinned to +-X_MAX
        n = (int)randInt(1, GEN_N_CAP);
        q = (int)randInt(1, GEN_Q_CAP);
        maxBoundValues = true;
    } else if (mode < 80) {
        // n pinned to the true constraint boundary N_MAX. This is the case
        // that catches fixed-size-array off-by-one bugs -- e.g. a global
        // array declared as exactly `long long diff[MAX_N]` when the
        // difference-array trick needs an index up to n (i.e. MAX_N).
        // q is kept small so O(n*q) brute force stays fast; the boundary
        // write at r = n-1 (so diff[r+1] = diff[n]) is always exercised.
        n = N_MAX;
        q = (int)randInt(1, 50);
        forceLastAtN = true;
    } else {
        // general random
        n = (int)randInt(1, GEN_N_CAP);
        q = (int)randInt(1, GEN_Q_CAP);
    }

    printf("%d %d\n", n, q);
    for (int i = 0; i < q; i++) {
        int l, r;
        if (allEqual) {
            l = 0;
            r = n - 1;
        } else {
            l = (int)randInt(0, n - 1);
            r = (int)randInt(l, n - 1);
        }
        if (forceLastAtN && i == q - 1) {
            r = n - 1;
            if (l > r) l = r;
        }
        long long x;
        if (maxBoundValues) {
            x = (randInt(0, 1) == 0) ? X_MAX : -X_MAX;
        } else {
            x = randInt(-X_MAX, X_MAX);
        }
        printf("%d %d %lld\n", l, r, x);
    }
    return 0;
}
