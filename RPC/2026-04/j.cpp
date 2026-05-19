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
    cout.tie(NULL);
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define MAXN 300010
#define MAXL 32
#define int ll
#define EPS 1e-9
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'
#define pid pair<int, double>
#define vid vector<pid>
using namespace std;
int up[MAXL][MAXN];
__int128_t up_k[MAXL][MAXN];
__int128_t up_c[MAXL][MAXN];
int up_d[MAXL][MAXN]; // up_delta
int req[MAXL][MAXN];  // quanto eu preciso ter pra dá esse pulo

signed main()
{
    optimize;
    int n, e;
    cin >> n >> e;

    vi dp(n, INF);
    int curr = 0;
    map<int, int> last_idx;
    last_idx[0] = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        curr += i;
        curr %= n;
        if (last_idx.count(curr))
            dp[i % n] = min(dp[i % n], i - last_idx[curr]);
        last_idx[curr] = i;
    }

    auto calc_c = [&](int k)
    {
        return (k * (k - 1)) / 2;
    };

    for (int i = 0; i < n; i++)
    {
        up[0][i] = (i - dp[i] + 2 + n) % n;
        up_k[0][i] = dp[i];
        up_c[0][i] = calc_c(dp[i]);
        up_d[0][i] = dp[i] - 2;
        req[0][i] = dp[i];
    }

    for (int j = 1; j < MAXL; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int pai = up[j - 1][i];
            up[j][i] = up[j - 1][pai];
            up_k[j][i] = up_k[j - 1][i] + up_k[j - 1][pai];
            up_c[j][i] = up_c[j - 1][i] + up_c[j - 1][pai] + up_k[j - 1][pai] * up_d[j - 1][i];
            up_d[j][i] = up_d[j - 1][i] + up_d[j - 1][pai];
            req[j][i] = max(req[j - 1][i], up_d[j - 1][i] + req[j - 1][pai]);
        }
    }

    map<int, bool> vis;

    auto pa = [&](int n, int qtd)
    {
        // dbg(n);
        // dbg(qtd);
        return (((n - qtd + 1) + n) * qtd) / 2;
    };

    curr = e;
    __int128_t ans = 0;
    long long jumps = 0; // Vai contar os pulos
    while (curr > 0)
    {
        long long start_jumps = jumps;
        for (int j = MAXL - 1; j >= 0 && curr > 0; j--)
        {
            // dbg(req[j][curr % n]);
            if (req[j][curr % n] > curr)
                continue;
            __int128_t val = up_k[j][curr % n] * curr - up_c[j][curr % n];
            curr -= up_d[j][curr % n];
            ans += val;
            jumps += (1LL << j);
        }
        if (jumps == start_jumps)
            break;
        if (jumps >= (1LL << 50))
        {
            cout << "infinity\n";
            return 0;
        }
    }

    if (curr > 0)
        ans += pa(curr, curr);

    cout << (int)ans << endl;
    return 0;
}
