//
// Created by Luis on 18/01/2024.
//
//
// Created by Luis on 18/01/2024.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cmath>

#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101
#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

ll comb3(ll n) {
    auto ans = (n * (n * n - 3 * n + 2)) / 6;
    return ans;
}

ll comb2(ll n) {
    auto ans = (n * n - n) / 2;
    return ans;
}


void solve() {
    int n;
    cin >> n;
    vi c(n);
    map<pii, ll> travel;
    for (auto &x: c) cin >> x;
    vector<ll> ps1(n), ps2(n);
    ps1[0] = 0, ps2[n - 1] = 0;
    travel[{0, 1}] = 1;
    travel[{n - 1, n - 2}] = 1;
    for (int i = 1; i < n - 1; i++) {
        auto op1 = abs(c[i] - c[i - 1]);
        auto op2 = abs(c[i] - c[i + 1]);
        if (op1 < op2) {
            travel[{i, i - 1}] = 1;
            travel[{i, i + 1}] = op2;
        } else {
            travel[{i, i + 1}] = 1;
            travel[{i, i + -1}] = op1;
        }
    }
    ll sum = 0;
    for (int i = 1; i < n; i++) {
        sum += travel[{i - 1, i}];
        ps1[i] = sum;
    }
    sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum += travel[{i + 1, i}];
        ps2[i] = sum;
    }

    int m;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (x < y) {
            cout << ps1[y] - ps1[x] << endl;
        } else {
            cout << ps2[y] - ps2[x] << endl;
        }
    }
}


int main() {
    optimize;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

