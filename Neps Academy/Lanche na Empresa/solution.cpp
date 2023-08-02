//
// Created by Luis on 28/07/2023.
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

int n ,c;

vector<vii> grafo;

vi dijkstra(int s){
    vi dist(n+1,INF);
    dist[s] = 0;
    priority_queue<pii, vii, greater<pii>> pq;
    pq.push({0,s});

    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto &it : grafo[u]){
            int v = it.first;
            int w = it.second;

            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}

int solve(){
    
}


int main(int argc, char** argv)
{
    optimize;
    cin >> n >> c;
    grafo.resize(n+1);
    while(c--){
        int u ,v , custo;
        cin >> u >> v >> custo;
        grafo[u].EB(v,custo);
        grafo[v].EB(u,custo);
    }
    return 0;
}