// brute.cpp
// Oracle: applies each update with a literal elementwise loop over [l, r].
// Correct by construction -- it does exactly what the problem statement
// defines "range add" to mean, with no algebraic transform to get wrong.
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<long long> a(n, 0);
    for (int i = 0; i < q; i++) {
        int l, r;
        long long x;
        cin >> l >> r >> x;
        for (int j = l; j <= r; j++) a[j] += x;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
    return 0;
}
