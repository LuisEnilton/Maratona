//
// Created by Luis on 11/11/2023.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cmath>

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
    Arvore geradora minima
    Kruskal
    Complexidade: O(M log N)
    O algoritmo consiste em ordenar as arestas e ir adicionando as arestas
    de menor peso que não formem ciclo.

    Union find
    Complexidade: O(log N)
    O algoritmo consiste em agrupar os vertices em conjuntos disjuntos
    e verificar se dois vertices pertencem ao mesmo conjunto.



*/



struct Aresta {
    int u, v;
    ll peso;
    Aresta() {}

    Aresta(int u, int v, ll peso) {
        this->u = u;
        this->v = v;
        this->peso = peso;
    }

    bool operator<(Aresta const &a) const {
        return peso < a.peso;
    }
};


struct Grafo {
    vector<Aresta> arestas;
    vector<int> pai;
    vector<int> sz;

    Grafo(int n) {
        pai.resize(n + 3);
        sz.resize(n + 3);
        for (int i = 0; i < n; i++) {
            pai[i] = i;
            sz[i] = 1;
        }
    }

    bool tem_ciclo(int u, int v) {

        return find(u) == find(v);
    }

    void addAresta(int u, int v, ll peso) {
        arestas.push_back(Aresta(u, v, peso));
    }

    inline void join(int u, int v){
        u = find(u);
        v = find(v);

        if(u == v) return;
        if(sz[v] > sz[u]) swap(u, v);

        pai[v] = u;
        sz[u] += sz[v];
    }

    int find(int u) {
        if (pai[u] == u) return u;
        return pai[u] = find(pai[u]);
    }

    vector<Aresta> Kruskal() {
        sort(ALL(arestas));

        vector<Aresta> arvore;
        for (auto &aresta: arestas) {
            int u = aresta.u;
            int v = aresta.v;
            ll peso = aresta.peso;

            if (!tem_ciclo(u, v)) {

                join(u, v);
                //adiciona a aresta na arvore
                arvore.push_back(aresta);
            }


        }
        return arvore;
    }

};

int main(int argc, char const *argv[]) {
    optimize;
    int n, m;
    cin >> n >> m;
    ll k;
    cin >> k;
    auto grafo = *new Grafo(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll peso;
        cin >> u >> v >> peso;
        grafo.addAresta(u, v, peso);
    }
    auto mst = grafo.Kruskal();
    ll ans = 0;
    for (auto x: mst) {
        ans+=x.peso;
    }
    cout << ans % k << endl;
    return 0;
}




