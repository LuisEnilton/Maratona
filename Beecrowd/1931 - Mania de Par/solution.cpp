//
// Created by luise on 04/07/2023.
//
//
// Created by luise on 04/07/2023.
//
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

vector<vi> dijkstra(int origem){
    //fila.top () = (distancia, vertice)
    priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> fila;

    vector<vi> distancias(N+1,vi(2,INF));
    //distancias[u][0]
    distancias[origem][0] = 0;
    //A distância par começa em 0 a impar não
    fila.push({0,{0,origem}});

    vector<vector<bool>> visitados(N+1,vector<bool>(2,false));

    while(!fila.empty()){
        auto x = fila.top().second;
        int atual = x.first;
        bool paridade = x.second;
        fila.pop();
        //Existe diferença entre visitar o vertice com um caminho impar e par
        if(visitados[atual][paridade]) continue;

        visitados[atual][paridade] = true;

        for(auto [vizinho,custo] : grafo[atual]){
            bool next = !paridade;
            if(distancias[vizinho][next] > distancias[atual][paridade] + custo){

                distancias[vizinho][next] = distancias[atual][paridade] + custo;
                //o msm vertice pode ser inserido mais de uma vez na fila, mas como ele já foi visitado, não será processado novamente
                fila.push({distancias[vizinho][next],{vizinho,next}});
            }
        }
    }
    return distancias;

}

int main(int argc, char const *argv[])
{
    optimize;

    cin >> N >> M;


    for (int i = 0, u, v, c; i < M; i++)
    {
        cin >> u >> v >> c;

        grafo[u].emplace_back(v,c);
        grafo[v].emplace_back(u,c);
    }

    auto dist = dijkstra(1);

    if (dist[N][0] == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dist[N][0] << endl;
    }

    return 0;
}


/*




*/

