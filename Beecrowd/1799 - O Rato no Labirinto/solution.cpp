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

int N, M;

vector<pii > grafo[MAXN];


int to_int(string s) {
    int soma = 0;
    for (char c: s) {
        soma += int(c);
    }
    return soma;
}

vector<int> dijkstra(int origem) {
    //fila.top () = (distancia, vertice)
    priority_queue<pii, vector<pii >, greater<pii>> fila;

    vector<int> distancias(MAXN, INF);

    distancias[origem] = 0;

    fila.push({0, origem});

    vector<bool> visitados(MAXN, 0);

    while (!fila.empty()) {
        auto [dist, atual] = fila.top();

        fila.pop();

        if (visitados[atual]) continue;

        visitados[atual] = true;

        for (auto [vizinho, custo]: grafo[atual]) {
            if (distancias[vizinho] > dist + custo) {
                distancias[vizinho] = dist + custo;
                //o msm vertice pode ser inserido mais de uma vez na fila, mas como ele já foi visitado, não será processado novamente
                fila.push({distancias[vizinho], vizinho});
            }
        }
    }
    return distancias;

}

int main(int argc, char const *argv[]) {
    optimize;
    cin >> N >> M;
    int inicio;
    int final;
    for (size_t i = 0; i < M; i++) {
        string u, v;

        cin >> u >> v;
        cin.ignore();
        if (u == "Entrada") {
            inicio = to_int(v);
            continue;
        }
        if (v == "Saida") {
            final = to_int(u);
            continue;
        }
        grafo[to_int(u)].EB(to_int(v), 1);
        grafo[to_int(v)].EB(to_int(u), 1);
    }

    auto distancias_inicio = dijkstra(inicio);
    auto distancias_queijo = dijkstra(to_int("*"));

    cout << distancias_inicio[to_int("*")] + distancias_queijo[final] + 2 << endl;

    return 0;
}

