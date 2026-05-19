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
#define MAXL 20
#define int ll
#define EPS 1e-9
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'
using namespace std;

signed main()
{
    optimize;
    int n, m;
    cin >> n >> m;

    vi c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    vector<vii> g(n + 1);
    vii arestas;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
        arestas.emplace_back(u,v);
    }
    vector<vi> dag_parents(n + 1);
    vi ord;
    vi pai(n + 1);
    vi dist(n + 1, INF);
    auto bfs = [&]()
    {
        queue<pii> q;
        
        dist[1] = 0;
        q.emplace(1,0);

        while (q.size())
        {

            auto [u,p] = q.front();
            q.pop();
            ord.push_back(u);
            // dbg(u);
            for (auto [v, id] : g[u])
            {
                if(v == p) continue;
                // dbg(dist[v]);
                if (dist[v] == INF)
                {
                    dist[v] = dist[u] + 1;
                    dag_parents[v].push_back(u);
                    
                    q.emplace(v,u);
                }
                else if (dist[v] == dist[u] + 1)
                {
                    dag_parents[v].push_back(u);
                }
                
            }
        }
    };
    bfs();

    vi depth(n + 1);
    vector<vi> up(MAXL, vi(n + 1));
    auto get_lca = [&](int u, int v)
    {
        if (depth[u] < depth[v])
            swap(u, v);

        for (int j = MAXL - 1; j >= 0; j--)
        {

            if (depth[u] - (1 << j) < depth[v])
                continue;
            u = up[j][u];
        }

        if (u == v)
            return u;

        for (int j = MAXL - 1; j >= 0; j--)
        {

            if (up[j][u] == up[j][v])
                continue;
            u = up[j][u];
            v = up[j][v];
        }
        return up[0][u];
    };
    vector<vi> dom_tree(n + 1);

    auto build_dom = [&]()
    {
        depth[1] = 0;

        for (int i = 0; i < MAXL; i++)
            up[i][1] = 1;

        for (auto u : ord)
        {
            // dbg(u);
            if (u == 1)
                continue;

            int idom = dag_parents[u][0];
            // o dominador dele vai ser o lca entre todos os pais
            for (int i = 1; i < dag_parents[u].size(); i++)
            {
                idom = get_lca(idom, dag_parents[u][i]);
            }

            dom_tree[idom].push_back(u);
            depth[u] = depth[idom] + 1;
            up[0][u] = idom;

            for (int i = 1; i < MAXL; i++)
            {
                up[i][u] = up[i - 1][up[i - 1][u]];
            }
        }
    };
    build_dom();
    vi cnt(n + 1);
    function<void(int, int)> dfs = [&](int u, int p)
    {
        cnt[u] = c[u];

        for (auto v : dom_tree[u])
        {
            if (v == p)
                continue;
            dfs(v, u);
            cnt[u] += cnt[v];
        }
    };
    vi ans(m);
    dfs(1, 0);

    // for(int i = 1; i <=n;i++){
    //     dbg(i);
    //     for(auto v : dom_tree[i]){
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < m; i++)
    {
        // dbg(i);
        // dbg(not_used[i]);
        auto [u, v] = arestas[i];
        if (depth[u] > depth[v])
            swap(u, v);
        if(dist[v] != dist[u] + 1) continue;   
        // dbg(v);
        if (dag_parents[v].size() > 1)
            continue;
        ans[i] = cnt[v];
    }
    for (auto x : ans)
    {
        cout << x << endl;
    }
    return 0;
}
