//
// Created by luise on 04/07/2023.
//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
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

int N, M;

struct Grafo
{
    vector<vector<pii>> grafo;

    Grafo(int N)
    {
        grafo.resize(N + 1);
    }

    void addAresta(int u, int v, int c)
    {
        grafo[u].EB(v, c);
        grafo[v].EB(u, c);
    }

    vector<vi> Dijkstra(int origem)
    {
        vector<vi> distancias(N + 1, vi(2, INF));

        vector<vector<bool>> vis(N + 1, vector<bool>(2, false));

        /*
            {custo, vertice}
            {custo, {vertice, paridade}}
        */
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

        distancias[origem][0] = 0;

        pq.push({0, {origem, 0}});

        while (!pq.empty())
        {
            auto x = pq.top().second;
            int u = x.first;
            bool paridade = x.second;

            pq.pop();

            if (vis[u][paridade]) continue;

            vis[u][paridade] = true;

            for (auto &curr : grafo[u])
            {
                int v = curr.first;
                int c = curr.second;

                bool next = !paridade;

                // Relaxamento
                if (distancias[v][next] > distancias[u][paridade] + c)
                {
                    distancias[v][next] = distancias[u][paridade] + c;

                    pq.push({distancias[v][next], {v, next}});
                }
            }
        }

        return distancias;
    }
};

int main(int argc, char** argv)
{
    optimize;

    cin >> N >> M;

    Grafo g(N);

    for (int i = 0, u, v, c; i < M; i++)
    {
        cin >> u >> v >> c;

        g.addAresta(u, v, c);
    }

    auto dist = g.Dijkstra(1);

    if (dist[N][0] == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dist[N][0] << endl;
    }

    return 0;
}
