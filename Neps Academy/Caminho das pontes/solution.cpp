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
    Djikstra: Menor caminho , complexidade : O(ElogV)
    Floyd-Warshall: Menor caminho entre todos os pares de vértices, complexidade : O(V^3)
    Bellman-Ford: Menor caminho com arestas negativas, complexidade : O(VE)



*/

int N,M;

vector<pii> grafo[MAXN];

vector<int> dijkstra(int origem){
    //fila.top () = (distancia, vertice)
    priority_queue<pii, vector<pii>, greater<pii>> fila;

    vector<int> distancias(N+10,INF);
    
    distancias[origem] = 0;
    
    fila.push({0,origem});

    vector<bool> visitados(N+10,0);

    while(!fila.empty()){
        auto [dist,atual] = fila.top();

        fila.pop();

        if(visitados[atual]) continue;

        visitados[atual] = true;

        for(auto [vizinho,custo] : grafo[atual]){
            if(distancias[vizinho] > dist + custo){
                
                distancias[vizinho] = dist + custo;
                //o msm vertice pode ser inserido mais de uma vez na fila, mas como ele já foi visitado, não será processado novamente
                fila.push({distancias[vizinho],vizinho});
            }
        }
    }
    return distancias;

}

int main(int argc, char const *argv[])
{
    optimize;
    cin>>N>>M;

    for (size_t i = 0; i < M; i++)
    {
        int u,v,custo;

        cin>>u>>v>>custo;

        grafo[u].EB(v,custo);
        grafo[v].EB(u,custo);
    }
    
    auto distancias = dijkstra(0);

    cout<<distancias[N+1]<<endl;


    return 0;
}

