#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int z_a = 0, o_a = 0;
    for (char c : a) {
        if (c == '0') z_a++;
        else o_a++;
    }
    int z_b = 0, o_b = 0;
    for (char c : b) {
        if (c == '0') z_b++;
        else o_b++;
    }
    return min(z_a, o_b) + min(o_a, z_b);
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    freopen("hamming.in", "r", stdin);
    int t; cin >> t; while (t--) cout << solve() << '\n';
    return 0;
}
