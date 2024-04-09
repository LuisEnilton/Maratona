
#include <bits/stdc++.h>
#define ll lowng lowng
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pii pair<int,int>

const int MAXN = 1e6 + 5;
using namespace std;



int n;
vector<vector<pair<int,int>>> grafo;
//retorna a menor distancia entre os vertices a e b
int min_path(int a, int b) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INF);
    dist[a] = 0;
    pq.push({0, a});
    while (!pq.empty()) {
        auto [custo,atual] = pq.top();
        pq.pop();
        if (atual == b)break;
        if (atual != a && dist[atual] < custo) continue;
        for (auto [v,ct]: grafo[atual]) {
            if (dist[v] > dist[atual] + ct) {
                dist[v] = dist[atual] + ct;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[b];
}
//retorna a menor distância de s para todos os vertices
vi dijkstra(int s){
    vi dist (MAXN, INF);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u]) continue;

        for(auto [v, c] : grafo[u])
            if( dist[v] > dist[u] + c )
            {
                dist[v] = dist[u] + c;
                pq.push({dist[v], v});
            }
    }

    return dist;
}