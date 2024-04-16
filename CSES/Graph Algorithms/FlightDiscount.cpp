// Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cmath>
#define int long long
#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int, int>
#define piii pair<pii,int>
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

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>
int n, m;
vii grafo[MAXN];
pii pai[MAXN];
vii dijkstra(int o)
{
    pai[o] = {-1, 0};
    priority_queue<piii, vector<piii>, greater<>> pq;
    vii dist(n+2, {INF,0});
    dist[o].first = 0;
    pq.emplace(0, o,0);
    while (!pq.empty())
    {
        auto [x, l] = pq.top();
        auto [d,u] = x;
        pq.pop();
        if (d > dist[u].first)
            continue;

        for (auto [v, c] : grafo[u])
        {
            if(l >= c){
                if (d + c < dist[v].first)
            {
                dist[v].first = d+ c;
                dist[v].second = l;
                pq.emplace(dist[v], v,l);
                pai[v] = {u, c};
            }
            }else{
                l = c;
                if (d + l/2 < dist[v].first)
            {
                dist[v].first = d+ l/2;
                dist[v].second = l;
                pq.emplace(dist[v], v,l);
                pai[v] = {u, c};
            }
            }
            
        }
    }
    return dist;
}

signed main()
{
    optimize;
    
    cin >> n >> m;
    while (m--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        grafo[u].EB(v, c);
        grafo[v].EB(u, c);
    }
    auto dist = dijkstra(1);
    //for(auto x : dist) cout << x << endl;
    
    
    cout << dist[n].second << endl;
    return 0;
}
