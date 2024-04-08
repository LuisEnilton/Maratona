// Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cmath>

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

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>
int n, m, c, k;
vi dijkstra(int s,vector<vii> &grafo){
	vi dist (MAXN, INF);

	priority_queue<pii, vector<pii>, greater<pii>> fila;
	fila.push({0, s});
	dist[s] = 0;

	while(!fila.empty())
	{
		auto [d, u] = fila.top();
		//cout << d << " " << u << endl;
        fila.pop();

		if(d > dist[u]) continue;

		for(auto [v, c] : grafo[u])
            if( dist[v] > dist[u] + c )
			{
				dist[v] = dist[u] + c;
				fila.push({dist[v], v});
			}
	}

	return dist;
}


int main()
{
    optimize;
    
    while (cin >> n >> m >> c >> k && (n != 0 || m != 0 || c != 0 || k != 0))
    {
        vector<vii> grafo(n + 2);
        while (m--)
        {
            int u, v, p;
            cin >> u >> v >> p;
            if(u > v) swap(u,v);
            if(u < c && v  == u + 1|| u >= c)
                grafo[u].EB(v,p);
            grafo[v].EB(u,p);

        }
        auto v = dijkstra(k,grafo);
        cout << v[c-1] << endl;
    }
    return 0;
}
