//
// Created by Luis on 22/08/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
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
#define MAXN 100010
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;

int N, Q, nivel[MAXN], ancestral[MAXN][MAXL];
pii dp[MAXN][MAXL];
vii grafo[MAXN];

void dfs(int u, int p = -1)
{
    for (auto [v, c] : grafo[u])
    {
        if (v == p) continue;

        dp[v][0] = {c, c};
        nivel[v] = nivel[u] + 1;
        ancestral[v][0] = u;

        dfs(v, u);
    }
}

pii join(pii a, pii b)
{
    pii ans;

    ans.first = min(a.first, b.first);
    ans.second = max(a.second, b.second);

    return ans;
}

void precalc()
{
    for (int i = 0; i <= N; i++)
    {
        nivel[i] = 0;

        for (int j = 0; j < MAXL; j++)
            ancestral[i][j] = -1;
    }

    dfs(1);

    for (int j = 1; j < MAXL; j++)
        for (int i = 1; i <= N; i++)
            if (ancestral[i][j - 1] != -1 && ancestral[ancestral[i][j - 1]][j - 1] != -1)
            {
                ancestral[i][j] = ancestral[ancestral[i][j - 1]][j - 1];
                dp[i][j] = join(dp[i][j - 1], dp[ancestral[i][j - 1]][j - 1]);
            }
}

pii lca(int u, int v)
{
    if (nivel[u] < nivel[v]) swap(u, v);

    //NEUTRO
    pii ans = {INF, -INF};

    for (int i = MAXL - 1; i >= 0; i--)
        if (ancestral[u][i] != -1 && nivel[ancestral[u][i]] >= nivel[v])
        {
            // JUNTA AS DUAS PARTES
            ans = join(ans, dp[u][i]);
            u = ancestral[u][i];
        }

    if (u == v) return ans;

    for (int i = MAXL - 1; i >= 0; i--)
        if (ancestral[u][i] != -1 && ancestral[v][i] != -1 && ancestral[u][i] != ancestral[v][i])
        {
            ans = join(ans, dp[u][i]);
            ans = join(ans, dp[v][i]);
            u = ancestral[u][i], v = ancestral[v][i];
        }

    ans = join(ans, dp[u][0]);
    ans = join(ans, dp[v][0]);

    return ans;
}

int main(int argc, char** argv)
{
    optimize;

    int T;

    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        cin >> N;

        for (int i = 0; i <= N; i++)
        {
            grafo[i].clear();
        }

        for (int i = 1, u, v, c; i < N; i++)
        {
            cin >> u >> v >> c;

            grafo[u].push_back({v, c});
            grafo[v].push_back({u, c});
        }

        precalc();

        cin >> Q;

        cout << "Case " << t << ":" << endl;

        while (Q--)
        {
            int u, v;
            cin >> u >> v;

            auto ans = lca(u, v);
            cout << ans.first << " " << ans.second << endl;
        }
    }

    return 0;
}