#include <bits/stdc++.h>
#define int long long
using namespace std;

bool can(string &s) {
    int n = s.length();
    vector<bool> v(n), is_p(n);
    vector<int> p;
    int start = 0, end = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 's') start = i;
        if (s[i] == 'e') end = i;
        if (s[i] == 'o') p.push_back(i), is_p[i] = true;;
    }
    bool reach_p = false;
    auto valid = [&](int i) -> bool {
        return i >= 0 and i < n and not v[i] and s[i] != '#';
    };
    queue<int> bfs;
    bfs.push(start);
    while (bfs.size()) {
        int i = bfs.front(); bfs.pop();
        if (v[i]) continue;
        v[i] = true;
        if (not reach_p and is_p[i]) {
            reach_p = true;
            for (int j : p) bfs.push(j);
        }
        if (valid(i + 1)) bfs.push(i + 1);
        if (valid(i - 1)) bfs.push(i - 1);
    }
    return v[end];
}

int solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (not can(s)) return 0;
    int start = 0, end = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 's') start = i;
        if (s[i] == 'e') end = i;
    }
    auto valid = [&](int i) -> bool {
        return i >= 0 and i < n and s[i] == '.';
    };
    if (valid(start - 1)) {
        string t = s;
        t[start - 1] = '#';
        if (not can(t)) return 1;
    }
    if (valid(start + 1)) {
        string t = s;
        t[start + 1] = '#';
        if (not can(t)) return 1;
    }
    if (valid(end + 1)) {
        string t = s;
        t[end + 1] = '#';
        if (not can(t)) return 1;
    }
    if (valid(end - 1)) {
        string t = s;
        t[end - 1] = '#';
        if (not can(t)) return 1;
    }
    if (valid(start - 1) and valid(start + 1)) {
        string t = s;
        t[start - 1] = t[start + 1] = '#';
        if (not can(t)) return 2;
    }
    if (valid(end - 1) and valid(end + 1)) {
        string t = s;
        t[end - 1] = t[end + 1] = '#';
        if (not can(t)) return 2;
    }
    if (valid(start - 1) and valid(end - 1)) {
        string t = s;
        t[start - 1] = t[end - 1] = '#';
        if (not can(t)) return 2;
    }
    if (valid(start + 1) and valid(end - 1)) {
        string t = s;
        t[start + 1] = t[end - 1] = '#';
        if (not can(t)) return 2;
    }
    if (valid(start - 1) and valid(end + 1)) {
        string t = s;
        t[start - 1] = t[end + 1] = '#';
        if (not can(t)) return 2;
    }
    if (valid(start + 1) and valid(end + 1)) {
        string t = s;
        t[start + 1] = t[end + 1] = '#';
        if (not can(t)) return 2;
    }
    return -1;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    freopen("portals.in", "r", stdin);
    int t; cin >> t; while (t--) cout << solve() << '\n';
    return 0;
}
