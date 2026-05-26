#include <bits/stdc++.h>
#define long long long
using namespace std;
const long inf = 1e18;

void sum_over_subsets(int n, vector<long> &f) {
    int full = (1 << n) - 1;
    for (int i = 0; i < n; ++i) {
        int bit = 1 << i;
        for (int mask = 0; mask <= full; ++mask) if (mask & bit) {
            f[mask ^ bit] += f[mask];
        }
    }
}

void solve() {
    int t, n; cin >> t >> n;
    vector<long> f(1 << t);
    for (int k = 0; k < n; ++k) {
        string s; cin >> s;
        int x = 0;
        for (int i = 0; i < t; ++i) if (s[i] == '1') {
            x |= 1 << i;
        }
        f[x]++;
    }
    sum_over_subsets(t, f);
    for (long &x : f) x = n - x;
    vector<vector<long>> memo(t, vector<long>(1 << t, -1));
    vector<vector<int>> next(t, vector<int>(1 << t, -1));
    int full = (1 << t) - 1;
    auto dfs = [&](auto &dfs, int i, int mask) -> long {
        if (mask == 0) return t * (n - f[full]);
        if (memo[i][mask] != -1) return memo[i][mask];
        long best = inf;
        for (int k = 0; k < t; ++k) if (mask & (1 << k)) {
            long prev = f[full ^ mask];
            long after = f[full ^ (mask ^ (1 << k))];
            long curr = (after - prev) * (i + 1) + dfs(dfs, i + 1, mask ^ (1 << k));
            if (curr < best) {
                best = curr;
                next[i][mask] = k;
            }
        }
        return memo[i][mask] = best;
    };
    cout << dfs(dfs, 0, full) << '\n';
    int mask = full;
    int i = 0;
    while (mask) {
        int x = next[i][mask];
        mask ^= 1 << x;
        cout << x + 1 << " \n"[mask == 0];
        i++;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    freopen("tests.in", "r", stdin);
    int t; cin >> t; while (t--) solve();
    return 0;
}
