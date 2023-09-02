#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <string>
#include <algorithm>
#include <set>
#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 100000010
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
#define MAXN 101010
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;

/*
    -Como saber se uma aresta faz parte de um caminho minimo?
    -Se a distancia do vertice de origem até o vertice u/v + o custo da aresta + a distancia do vertice u/v
    até o vertice de destino for igual a distancia minima do vertice de origem até o vertice de destino,
    então a aresta faz parte do caminho minimo
*/

struct Grafo
{

    vector<vector<pii>> grafo;
    int N;

    // construtor
    Grafo(int N)
    {
        grafo.resize(N + 1);

    }

    vector<int> dijkstra(int origem)
    {
        // fila.top () = (distancia, vertice)
        priority_queue<pii, vector<pii>, greater<pii>> fila;

        vector<int> distancias(N + 10, INF);

        distancias[origem] = 0;

        fila.push({0, origem});

        vector<bool> visitados(N + 10, 0);

        while (!fila.empty())
        {
            auto [dist, atual] = fila.top();

            fila.pop();

            if (visitados[atual])
                continue;

            visitados[atual] = true;

            for (auto [vizinho, custo] : grafo[atual])
            {
                if (distancias[vizinho] > dist + custo)
                {
                    distancias[vizinho] = dist + custo;
                    // o msm vertice pode ser inserido mais de uma vez na fila, mas como ele já foi visitado, não será processado novamente
                    fila.push({distancias[vizinho], vizinho});
                }
            }
        }
        return distancias;
    }

    void add_aresta(int origem, int destino, int custo)
    {
        grafo[origem].EB(destino, custo);
        grafo[destino].EB(origem, custo);
    }
};

vector<pii> grafo[MAXN];
int N, M;
map<pii,int> arestas;


int main(int argc, char const *argv[])
{
    optimize;
    cin >> N >> M;

    Grafo normal(N), rev(N);

    for (int i = 0; i < M; i++)
    {
        int u, v, custo;
        
        cin >> u >> v >> custo;
        
        arestas[{u,v}] = custo;

        normal.add_aresta(u, v, custo);
        
        rev.add_aresta(v, u, custo);
    }

    auto origem = normal.dijkstra(1);
    
    auto destino = rev.dijkstra(N);

    int Q;

    cin >> Q;

    while (Q--)
    {
        // essa aresta faz parte do caminho minimo?
        int u, v;
        
        cin >> u >> v;

        if(arestas.count({u,v}) == 0){
            cout << "-1" << endl;
            continue;
        }
        else{
            int c = arestas[{u,v}];

            if(origem[u] + c + destino[v] == origem[N] || origem[v] + c + destino[u] == origem[N])
                cout << "Faz parte" << endl;
            else
                cout << "Nao faz parte" << endl;
        }
    }

    return 0;
}
