// sol_broken.cpp
// Plausible difference-array solution with one planted bug.
// See the comment block at the bottom for what's wrong.
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<long long> diff(n, 0);
    for (int i = 0; i < q; i++) {
        int l, r;
        long long x;
        cin >> l >> r >> x;
        diff[l] += x;
        diff[r] -= x;
    }

    vector<long long> a(n);
    long long running = 0;
    for (int i = 0; i < n; i++) {
        running += diff[i];
        a[i] = running;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
    return 0;
}

// Planted bug: the closing decrement lands on index `r` instead of `r + 1`
// (and diff is sized n instead of n + 1 to match). Since diff[r] is
// subtracted before a[r] is finalized in the prefix sum, the update's
// effect is cancelled one index too early -- the LAST index of every
// applied range silently fails to receive +x, unless some other update's
// own contribution happens to mask it. Most visible on single, non-
// overlapping range updates.
