//
// Created by luise on 22/11/2023.
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
int n, m;

pair<vi, vi > bfs(int o, vector<vi > &grafo) {
    queue<int> fila;
    vi pai(n + 2, - 1);
    fila.push(o);
    vi dist(n + 2, INF);
    dist[o] = 0;
    while (!fila.empty()) {
        auto u = fila.front();
        fila.pop();
        for (auto v: grafo[u]) {
            if (dist[v] >= dist[u] + 1) {
                dist[v] = dist[u] + 1;
                pai[v] = u;
                fila.push(v);
            }
        }
    }
    return {dist, pai};
}

int main() {
    optimize;
    vector<vi > grafo;
    vector<vi > grafo_rev;
    int a, b;
    cin >> n >> m >> a >> b;
    grafo.resize(n + 2);
    grafo_rev.resize(n + 2);
    while (m--) {
        int u, v;
        cin >> u >> v;
        grafo[u].EB(v);
        grafo_rev[v].EB(u);
    }
    auto [dist, pai] = bfs(0, grafo);
    auto [distA, x] = bfs(a, grafo_rev);
    auto [distB, y] = bfs(b, grafo_rev);
    int ans;
    if (dist[a] + distA[b] <= dist[b] + dist[a]) {
        ans = dist[a] + distA[b];
    } else if (dist[b] + distB[a] <= dist[b] + dist[a]) {
        ans = dist[b] + distB[a];
    } else {
        set<pii > caminho;
        int ant = a;
        for (int p = pai[a]; p != -1; p = pai[p]) {
            caminho.insert({p,ant});
        }
        ant = b;
        int qtd = 0;
        for(int p = pai[b];p!=-1;p = pai[p]){
            pii aresta = {ant,p};
            if(caminho.count(aresta)) qtd++;
        }
        ans = dist[a] + dist[b] - qtd;
    }
    cout << ans << endl;
    return 0;
}

