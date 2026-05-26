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
#define MAXN 200010
#define int ll
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

int n;
int sz[MAXN], lvl[MAXN];
vi grafo[MAXN];
void dfs(int u, int p = 0, int l = 0)
{
    sz[u] = 1;
    lvl[u] = l;
    for (auto v : grafo[u])
    {
        if (v == p)
            continue;
        dfs(v, u, l + 1);
        sz[u] += sz[v];
    }
}

signed main()
{
    optimize;
    int n, q;
    cin >> n >> q;
    int m = n - 1;
    vector<array<int, 3>> arestas(m);
    for (auto &[u, v, w] : arestas)
    {
        cin >> u >> v >> w;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }
    dfs(1);
    auto add = [&](int a, int b)
    {
        return (a + b) % MOD;
    };

    auto sub = [&](int a, int b)
    {
        return (((a - b) % MOD) + MOD) % MOD;
    };
    int ans = 0;

    auto calc = [&](int u, int v, int w)
    {
        if (lvl[u] > lvl[v])
            swap(u, v);

        int qtd = (sz[v] * (n - sz[v])) % MOD;
        int val = (qtd * w) % MOD;
        return val;
    };

    for (auto [u, v, w] : arestas)
    {
        ans = add(ans, calc(u, v, w));
    }

    while (q--)
    {
        int id, nw;
        cin >> id >> nw;
        id--;
        auto &[u, v, w] = arestas[id];
        ans = sub(ans, calc(u, v, w));
        ans = add(ans, calc(u, v, nw));
        w = nw;
        cout << ans << endl;
    }

    return 0;
}
