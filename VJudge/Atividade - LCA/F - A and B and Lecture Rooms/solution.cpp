//
// Created by Luis on 22/08/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>
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
#define MAXN 200010
#define MAXL 22
#define EPS 1e-9
#define endl '\n'

using namespace std;

int N, Q, ancestral[MAXN][MAXL], nivel[MAXN], sz[MAXN];
vi grafo[MAXN];

void dfs(int u, int p = -1)
{
    sz[u] = 1;

    for (auto v : grafo[u])
    {
        if (v != p)
        {
            nivel[v] = nivel[u] + 1;
            ancestral[v][0] = u;
            dfs(v, u);

            sz[u] += sz[v];
        }
    }
}

void precalc()
{
    memset(ancestral, -1, sizeof ancestral);

    dfs(1);

    for (int j = 1; j < MAXL; j++)
        for (int i = 1; i <= N; i++)
            if(ancestral[i][j - 1] != -1)
                ancestral[i][j] = ancestral[ancestral[i][j - 1]][j - 1];
}

int kth_ancestor(int u, int k)
{
    for (int i = MAXL - 1; i >= 0; i--)
        if (k & (1 << i) && u != -1)
            u = ancestral[u][i];

    return u;
}

int LCA(int u, int v)
{
    if (nivel[u] < nivel[v]) swap(u, v);

    u = kth_ancestor(u, nivel[u] - nivel[v]);

    if (u == v) return u;

    for (int i = MAXL - 1; i >= 0; i--)
        if (ancestral[u][i] != ancestral[v][i])
        {
            u = ancestral[u][i];
            v = ancestral[v][i];
        }

    return ancestral[u][0];
}

int query(int u, int v)
{
    if (u == v) return N;

    if (nivel[u] < nivel[v]) swap(u, v);

    int lca = LCA(u, v);

    int d = nivel[u] + nivel[v] - 2 * nivel[lca];

    if (d % 2) return 0;

    int k = d / 2;

    int esquerdo = kth_ancestor(u, k - 1);
    int meio = ancestral[esquerdo][0];

    if (meio == lca)
    {
        int direito = kth_ancestor(v, k - 1);

        return N - sz[direito] - sz[esquerdo];
    }
    else
    {
        return sz[meio] - sz[esquerdo];
    }
}

int main(int argc, char** argv)
{
    optimize;

    cin >> N;

    for (int i = 1, u, v; i < N; i++)
    {
        cin >> u >> v;

        grafo[u].PB(v);
        grafo[v].PB(u);
    }

    precalc();

    cin >> Q;

    while (Q--)
    {
        int u, v;
        cin >> u >> v;

        cout << query(u, v) << endl;
    }

    return 0;
}