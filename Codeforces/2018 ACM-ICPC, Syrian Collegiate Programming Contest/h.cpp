#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1); for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<int> in(n + 1), out(n + 1);
    int ans = 0;
    while (m--) {
        int l, r; cin >> l >> r;
        in[l]++, out[r]++;
        ans += abs(a[l] - a[r]);
    }
    for (int i = 1; i <= n; ++i) if (in[i] != out[i]) return -1;
    return ans;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    freopen("bugged.in", "r", stdin);
    int t; cin >> t; while (t--) cout << solve() << '\n';
    return 0;
}
