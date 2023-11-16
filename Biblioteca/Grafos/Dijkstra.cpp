
#include <bits/stdc++.h>
#define ll lowng lowng
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pii pair<int,int>

const int MAXN = 1e6 + 5;
using namespace std;


vector<int> rota;
int n;
vector<vector<pair<int,int>>> grafo;
//retorna a menor distancia entre os vertices a e b
int min_path(int a, int b) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    vector<int> dp(n, INF);
    dp[a] = 0;
    heap.push({0, a});
    while (!heap.empty()) {
        auto [custo,atual] = heap.top();
        heap.pop();
        if (atual == b)break;
        if (atual != a && dp[atual] < custo) continue;
        for (auto [v,ct]: grafo[atual]) {
            if (dp[v] > dp[atual] + ct) {
                dp[v] = dp[atual] + ct;
                heap.push({dp[v], v});
            }
        }
    }
    return dp[b];
}
//retorna a menor distância de s para todos os vertices
vi dijkstra(int s){
    vi dist (MAXN, INF);

    priority_queue<pii, vector<pii>, greater<pii>> fila;
    fila.push({0, s});
    dist[s] = 0;

    while(!fila.empty())
    {
        auto [d, u] = fila.top();
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