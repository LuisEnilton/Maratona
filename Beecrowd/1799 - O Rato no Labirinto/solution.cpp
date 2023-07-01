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
#define psi pair<string,int>
#define pis pair<int,string>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101
#define MAXN 1010100
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

int N, M;

map<string,vector<psi>> grafo;





map<string,int> dijkstra(string origem) {
    //fila.top () = (distancia, vertice)
    priority_queue<pis, vector<pis >,greater<pis>> fila;

    map<string,int> distancias;

    distancias[origem] = 0;
    fila.push({0,origem});

    map<string,bool> visitados;

    while (!fila.empty()) {
        auto [dist, atual] = fila.top();

        fila.pop();

        if (visitados[atual]) continue;

        visitados[atual] = true;

        for (auto [vizinho,custo]: grafo[atual]) {


            if ( distancias.find(vizinho) == distancias.end() ||distancias[vizinho] > dist + custo) {
                distancias[vizinho] = dist + custo;
                //o msm vertice pode ser inserido mais de uma vez na fila, mas como ele já foi visitado, não será processado novamente
                fila.push({distancias[vizinho],vizinho,});
            }
        }
    }
    return distancias;

}

int main(int argc, char const *argv[]) {
    optimize;
    cin >> N >> M;
    for (size_t i = 0; i < M; i++) {
        string u, v;

        cin >> u >> v;
        cin.ignore();
        grafo[u].EB(v,1);
        grafo[v].EB(u,1);

    }

    map<string,int> dist = dijkstra("Entrada");
    map<string,int> dist2 = dijkstra("*");

    int ans = dist["*"] + dist2["Saida"];

    cout<<ans<<endl;

    return 0;
}

