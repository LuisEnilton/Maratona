//
// Created by luise on 24/10/2023.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

const int maxn =10e5 + 10;
vector<pair<int,ll>> grafo[maxn];
int n,m;
vector<ll> dijkstra(int o,int ign){
    priority_queue<pii,vector<pii>,greater<>> pq;
    vector<ll> dist(n + 2,INFLL);
    vector<bool> visitados(n+2,false);
    visitados[ign] = true;
    dist[o] = 0;
    pq.push({0,o});
    while(!pq.empty()){
        auto [d,atual] = pq.top();
        pq.pop();
        if(visitados[atual]) continue;
        visitados[atual] = true;
        for(auto [v,custo] : grafo[atual]){
            if(d + custo < dist[v]){
                dist[v] = d+custo;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}

int main()
{
    optimize;
     cin >> n >> m;
    int p,g; cin >> p >> g;
    for(int i = 0 ; i< m;i++){
        int u,v;
        ll c;
        cin >> u >> v >> c;
        grafo[u].EB(v,c);
        grafo[v].EB(u,c);
    }
    vector<ll> dist1 = dijkstra(p,0);
    vector<ll> dist2 = dijkstra(p,g);
    int cnt =0;
    for(int i = 1; i <=n;i++){
        if(i == p || i == g) continue;
        if(dist1[i] == 2 * dist1[g] && dist2[i] > dist1[i]){
            cout << i << " ";
            cnt++;
        }
    }
    if(cnt == 0) cout << "*";
    cout << endl;
    return 0;
}

