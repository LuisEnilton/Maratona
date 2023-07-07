//
// Created by Luis on 06/07/2023.
//
//By eduardocesb
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

struct Aresta{
    int u,v,peso;
    Aresta(){}
    Aresta(int u,int v,int peso){
        this->u = u;
        this->v = v;
        this->peso = peso;
    }

    bool operator<(Aresta const& a) const{
        return peso < a.peso;
    }
};




struct Grafo{
    vector<Aresta> arestas;
    vector<int> pai;

    Grafo(int n){
        pai.resize(n);
        for(int i=0;i<n;i++){
            pai[i] = i;
        }
    }

    bool tem_ciclo(int u,int v){
        //Se elas tiverem o msm pai
        return find(u) == find(v);
    }
    void addAresta(int u,int v,int peso){
        arestas.push_back(Aresta(u,v,peso));
    }

    void join(int u,int v){
        u = find(u);
        v = find(v);

        pai[u] = v;
    }

    int find(int u){
        if(pai[u] == u) return u;
        return pai[u] = find(pai[u]);
    }

    vector<Aresta> Kruskal(){
        sort(ALL(arestas));
        vector<Aresta> arvore;
        for(auto &aresta: arestas){
            int u = aresta.u;
            int v = aresta.v;
            int peso = aresta.peso;

            if(!tem_ciclo(u,v)){

                join(u,v);
                //adiciona a aresta na arvore
                arvore.push_back(aresta);
            }


        }
        return arvore;
    }

};

int N, M;

int main(int argc, char **argv) {
    optimize;
    while((cin >> N >> M) && (N!=0 || M!=0)){

    Grafo rotas(N);
    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        rotas.addAresta(u, v, c);
    }

    auto arvore = rotas.Kruskal();
    int soma = 0;
    for (auto aresta: arvore) {
        soma += aresta.peso;
    }
    cout << soma << endl;
    }


    return 0;
}
