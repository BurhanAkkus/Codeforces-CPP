#include <bits/stdc++.h>
using namespace std;

// Iterative segment tree storing the INDEX of the minimum element.
// Ties -> smallest index. 0-based, half-open queries [l, r).
struct MinIdxSegTree {
    int n;
    vector<long long> a;   // values
    vector<int> t;         // t[node] = index of min in that node's range

    MinIdxSegTree(const vector<long long>& v) : n(v.size()), a(v), t(2 * v.size()) {
        for (int i = 0; i < n; i++) t[n + i] = i;
        for (int i = n - 1; i > 0; i--) t[i] = better(t[2 * i], t[2 * i + 1]);
    }

    int better(int i, int j) const {
        if (i == -1) return j;
        if (j == -1) return i;
        if (a[j] < a[i]) return j;
        if (a[i] < a[j]) return i;
        return min(i, j);
    }

    void update(int pos, long long val) {
        a[pos] = val;
        for (int i = (pos + n) >> 1; i >= 1; i >>= 1)
            t[i] = better(t[2 * i], t[2 * i + 1]);
    }

    // index of min in [l, r); -1 if empty
    int query(int l, int r) const {
        int resL = -1, resR = -1;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resL = better(resL, t[l++]);
            if (r & 1) resR = better(t[--r], resR);
        }
        return better(resL, resR);
    }
};

int main() {
    vector<long long> v = {5, 2, 7, 2, 9, 1};
    MinIdxSegTree st(v);
    cout << st.query(0, 6) << "\n";   // 5  (value 1)
    cout << st.query(0, 4) << "\n";   // 1  (value 2, tie -> smaller index)
    st.update(1, 0);
    cout << st.query(0, 6) << "\n";   // 1  (value 0)
    return 0;
}
