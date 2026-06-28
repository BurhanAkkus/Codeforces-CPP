#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<ll, pair<ll,char>> staircase; // key=x(row) ascending → y(col) descending

ll H, W;
vector<vector<char>> harita;

void insert(ll x, ll y, char letter) {
    // dominated if first entry with key >= x has y' >= y
    auto it = staircase.lower_bound(x);
    if (it != staircase.end() && it->second.first >= y)
        return;

    // find my previous
    
    // remove entries dominated by (x,y): x' <= x AND y' <= y
    auto it2 = staircase.begin();
    while (it2 != staircase.end() && it2->first <= x) {
        if (it2->second.first <= y)
            it2 = staircase.erase(it2);
        else
            it2++;
    }

    staircase[x] = {y, letter};
    auto new_it = staircase.find(x);
    ll prev_x = (new_it != staircase.begin()) ? prev(new_it)->first : 0;
    auto next_it = next(new_it);
    ll next_y = (next_it != staircase.end()) ? next_it->second.first : 0;
    // paint exactly the new unpainted rectangle (1-indexed input → 0-indexed array)
    for (ll i = prev_x + 1; i <= x; i++)
        for (ll j = y; j > next_y; j--)
            if(harita[i-1][j-1] == 'a')
                harita[i-1][j-1] = letter;
            else{
                break;
            }
        
}

void solve() {
    ll q;
    cin >> H >> W >> q;
    harita.assign(H, vector<char>(W, 'a'));

    vector<tuple<ll,ll,char>> queries(q);
    for (ll i = 0; i < q; i++) {
        ll r, c; char x;
        cin >> r >> c >> x;
        queries[i] = {r, c, x};
    }

    for (ll i = q - 1; i >= 0; i--) {
        auto& [r, c, x] = queries[i];
        insert(r, c, x);
    }

    for (ll i = 0; i < H; i++) {
        for (ll j = 0; j < W; j++)
            cout << (char)toupper(harita[i][j]);
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
