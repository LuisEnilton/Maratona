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
#define MAXN 501
#define MAXL 23
#define EPS 1e-9
#define endl '\n'
#define int ll
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

int freq[26];
const int N = 1e6 + 9, mod = 1e9 + 7;
int f[N], inv[N], finv[N];

void precalc()
{
    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = 1LL * i * f[i - 1] % mod;
    inv[1] = 1;
    for (int i = 2; i < N; i++)
    {
        inv[i] = (-(1LL * mod / i) * inv[mod % i]) % mod;
        inv[i] = (inv[i] + mod) % mod;
    }
    finv[0] = 1;
    for (int i = 1; i < N; i++)
        finv[i] = 1LL * inv[i] * finv[i - 1] % mod;
}

// Calcula o numero de combinações de 'n' em grupos de 'r' O(1)
int ncr(int n, int r)
{
    // RODAR O PRECALC!!
    if (n < r || n < 0 || r < 0)
        return 0;
    return 1LL * f[n] * finv[n - r] % mod * finv[r] % mod;
}

int perm_with_repetitions(int x, vi rep)
{
    // RODAR O PRECALC!!
    int resp = f[x];
    for (int r : rep)
    {
        resp = 1LL * resp * finv[r] % mod;
    }
    return resp;
}

signed main()
{
    optimize;
    string s;
    cin >> s;
    precalc();
    for (auto c : s)
    {
        freq[c - 'a']++;
    }
    int n = s.size();
    vi rep;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] <= 1)
            continue;
        rep.PB(freq[i]);
    }

    cout << perm_with_repetitions(n, rep) << endl;
    return 0;
}