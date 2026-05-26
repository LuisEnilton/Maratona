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

struct DSU
{
    vector<int> pai;
    vector<int> sz;

    DSU(int n)
    {
        pai.resize(n + 1);
        sz.resize(n + 1);
    }

    inline void resetDSU(int &n)
    {
        for (int i = 0; i <= n; i++)
            sz[i] = 1, pai[i] = i;
    }

    inline int find(int u)
    {
        return (pai[u] == u ? u : pai[u] = find(pai[u]));
    }

    inline void join(int u, int v)
    {
        u = find(u);
        v = find(v);

        if (u == v)
            return;
        if (sz[v] > sz[u])
            swap(u, v);

        pai[v] = u;
        sz[u] += sz[v];
    }
};

void solve()
{

    int n, q;
    cin >> n >> q;

    vi repre(26, -1); // representante de cada letra

    auto dsu = DSU(n);
    dsu.resetDSU(n);
    unordered_map<string, int> idx;
    for (int i = 0; i < n; i++)
    {

        string s;
        cin >> s;
        idx[s] = i;
        for (auto c : s)
        {

            if (repre[c - 'a'] == -1)
            {
                repre[c - 'a'] = i;
            }
            else
            {
                
                dsu.join(repre[c - 'a'], i);
            }
        }
        // for (int j = 0; j < n; j++)
        // {
        //     cout << dsu.find(j) << " ";
        // }
        // cout << endl;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << dsu.find(i) << endl;
    // }

    while (q--)
    {
        string a, b;
        cin >> a >> b;
        int ida = idx[a];
        int idb = idx[b];
        cout << (dsu.find(ida) == dsu.find(idb) ? "LUA" : "RYEI") << endl;
    }
}

signed main()
{
    optimize;
    int t = 1;
    //   cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
