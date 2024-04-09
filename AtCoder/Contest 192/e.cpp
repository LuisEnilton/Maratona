//
// Created by Luis on 08/04/2024.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cmath>

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
#define pli pair<ll,int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101
#define MAXN 101010
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

vector<pii > grafo[MAXN];

struct Aresta {
    int u, v;
    ll k, t;

    Aresta(int u, int v, ll t, ll k) : u(u), v(v), k(k), t(t) {}
};

vector<Aresta> arestas;

ll dijkstra(int o,int y) {
    priority_queue<pli, vector<pli >, greater<>> pq;
    vector<ll> dist(MAXN, INFLL);
    dist[o] = 0;
    pq.emplace(0, o);

    while (!pq.empty()) {
        auto [d, atual] = pq.top();
        pq.pop();
        if(atual == y) break;
        if(d > dist[atual]) continue;

        for (auto [v, id]: grafo[atual]) {
            ll k = arestas[id].k;
            ll t = arestas[id].t;
            ll time = (d % k == 0 ? 0 : k - (d % k));
            if (d + time + t < dist[v]) {
                dist[v] = d+ time + t;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist[y];
}


int main() {
    optimize;
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for (int i = 0; i < m; i++) {
        int u, v;
        ll t,k;
        cin >> u >> v >> t >> k;
        arestas.EB(u, v, t, k);
        grafo[u].EB(v, i);
        grafo[v].EB(u, i);
    }
    auto dist = dijkstra(x,y);
    cout << (dist == INFLL ? -1 : dist) << endl;
    return 0;
}

