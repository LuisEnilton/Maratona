//
// Created by Luis on 06/09/2023.
//
// Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int, int>
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
#define int ll
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

int m[MAXN][MAXL];

// Funciona pra Min, Max e GCD

int n;

void precalc(vi &a) {
    int n = a.size();
    // O primeiro nivel são os numeros lidos no input
    for (int i = 0; i < n; i++)
        m[i][0] = a[i];

    for (int k = 1; k < MAXL; k++) {
        for (int i = 0; i + (1 << k) - 1 < n; i++) {
            m[i][k] = gcd(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
        }
    }
}

int query(int l, int r) {
    if (l == n || r ==  -1) return 0;
    // RODAR O PRECALC
    int j = __builtin_clz(1) - __builtin_clz(r - l + 1);

    return gcd(m[l][j], m[r - (1 << j) + 1][j]);
}


signed main() {
    optimize;
    cin >> n;
    vi a(n);
    for (auto &x: a) cin >> x;
    precalc(a);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int gcdLeft = query(0, i - 1);
        int gcdRight = query(i + 1, n - 1);
        ans = max(ans, gcd(gcdLeft, gcdRight));
    }

    cout << ans << endl;

    return 0;
}

// 1 2 3 4 5
// 2 5 1 4 3 - 11
// 3 5 2 4 1 -

// 1 2 3 2 3 4 3 1 4
