//
// Created by Luis on 06/09/2023.
//
// Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define BT bitset<500>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define MAXN 1010101
#define int ll
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

const int N = 1e6 + 9;

int f[N], inv[N], finv[N];
void precalc()
{
    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = 1LL * i * f[i - 1] % MOD;
    inv[1] = 1;
    for (int i = 2; i < N; i++)
    {
        inv[i] = (-(1LL * MOD / i) * inv[MOD % i]) % MOD;
        inv[i] = (inv[i] + MOD) % MOD;
    }
    finv[0] = 1;
    for (int i = 1; i < N; i++)
        finv[i] = 1LL * inv[i] * finv[i - 1] % MOD;
}

// Calcula o numero de combinações de 'n' em grupos de 'r' O(1)
int ncr(int n, int r)
{
    if (n < r || n < 0 || r < 0)
        return 0;
    return 1LL * f[n] * finv[n - r] % MOD * finv[r] % MOD;
}

int fastExp(int base, int exp)
{
    int ret = 1LL;

    while (exp)
    {
        if ((exp & (1LL)))
            ret = (ret * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }

    return ret;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vi a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    sort(ALL(a));
    for (auto &x : a)
    {
        if (x < 0)
        {
            x = ((x % MOD) + MOD) % MOD;
        }
    }
    int den = ncr(n, k);
    int inv_den = fastExp(den, MOD - 2);
    // dbg(inv_den);
    int ans = 0;
    for (int i = k - 1; i < n; i++)
    {
        int aux = (ncr(i, k - 1) * a[i]) % MOD;
        ans = (ans + aux) % MOD;
    }

    for (int i = n - k; i >= 0; i--)
    {
        int aux = (ncr(n - i - 1, k - 1) * a[i]) % MOD;
        ans -= aux;
        ans = (((ans % MOD) + MOD) % MOD); // corrigir negativo
    }
    // cout << ans << endl;
    ans = (ans * inv_den) % MOD;
    cout << ans << endl;
}

signed main()
{
    optimize;
    precalc();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
