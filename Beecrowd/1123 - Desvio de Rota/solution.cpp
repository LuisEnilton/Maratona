//
// Created by luise on 05/07/2023.
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

vector<vii > grafo;
int n, c;

//calculates value of shortest path from a to b;
vi rota;
vi dijkstra(int s){
    vi dist (MAXN, INF);

    priority_queue<pii, vector<pii>, greater<pii>> fila;
    fila.push({0, s});
    dist[s] = 0;

    while(!fila.empty())
    {
        auto [d, u] = fila.top();
        fila.pop();

        if(d > dist[u] || u < c) continue;

        for(auto [v, custo] : grafo[u])
            if( dist[v] > dist[u] + custo )
            {
                dist[v] = dist[u] + custo;
                fila.push({dist[v], v});
            }
    }

    return dist;
}
int main() {
    optimize;
    int m, k;
    while (cin >> n >> m >> c >> k && (n != 0 || m != 0 || c != 0 || k != 0)) {
        rota.clear();
        rota.resize(c);
        grafo.clear();
        grafo.resize(n);
        while(m--){
            int u,v,p;
            cin >> u >> v>> p;
            grafo[u].EB(v,p);
            grafo[v].EB(u,p);
            if(u < c && v < c && abs(u-v) == 1){
                if(u > v) swap(u,v);
                    rota[u] = p;
            }
        }
        for(int i = c-2;i>=0;i--){
            rota[i]+=rota[i+1];
        }
        vi dist = dijkstra(k);
        int ans = dist[c - 1];
        for(int i = 0; i < c;i++){
            ans = min(ans,dist[i] + rota[i]);
        }
        cout << ans << endl;
    }
    return 0;
}

