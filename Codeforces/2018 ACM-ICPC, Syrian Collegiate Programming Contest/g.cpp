#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> l(n + 1); for (int i = 1; i <= n; ++i) cin >> l[i];
    vector<int> r(n + 1); for (int i = 1; i <= n; ++i) cin >> r[i];
    vector<int> ord(n); iota(ord.begin(), ord.end(), 1);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return (l[i] - r[i]) < (l[j] - r[j]);
    });
    vector<vector<int>> g(n + 1);
    vector<int> valid, invalid;
    for (int a : ord) {
        int need = l[a] - r[a];
        if (need > valid.size()) return void(cout << "-1\n");
        for (int i = 0; i < need; ++i) {
            g[valid[i]].push_back(a);
        }
        if (r[a] == 0) {
            valid.push_back(a);
        } else {
            invalid.push_back(a);
        }
    }
    for (int a : ord) {
        int need = r[a];
        if (need == 0) continue;
        if (need + 1 > invalid.size()) return void(cout << "-1\n");
        for (int i = 0; i < invalid.size(); ++i) {
            if (invalid[i] == a) continue;
            g[invalid[i]].push_back(a);
            need--;
            if (need == 0) break;
        }
    }
    vector<pair<int, int>> edges;
    for (int a = 1; a <= n; ++a) {
        for (int b : g[a]) edges.push_back({a, b});
    }
    cout << edges.size() << '\n';
    for (auto [a, b] : edges) cout << a << ' ' << b << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    freopen("topo.in", "r", stdin);
    int t; cin >> t; while (t--) solve();
    return 0;
}
