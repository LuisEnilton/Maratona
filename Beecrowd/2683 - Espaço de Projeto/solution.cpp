//
// Created by luise on 07/07/2023.
//
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
    int u;
    int v;
    int custo;



    Aresta(int u,int v , int custo){
        this->u = u;
        this->v = v;
        this->custo = custo;
    }

    bool operator <(Aresta const &a) const{
        return custo < a.custo;
    }

    bool operator >(Aresta const &a) const{
        return custo > a.custo;
    }

    bool operator ==(Aresta const &a) const{
        return custo == a.custo;
    }
};


struct Grafo{
    vector<Aresta> arestas;
    vi pai;
    vi altura;

    Grafo(int n){
        pai.resize(n+1);
        altura.resize(n+1);
        for (int i = 1; i <= n ; i++) {
            pai[i] = i;
            altura[i] = 1;
        }
    }

    void clear(){
        for (int i = 1; i <= pai.size()-1 ; i++) {
            pai[i] = i;
            altura[i] = 1;
        }
    }
    bool tem_ciclo(int u,int v ){
        return find(u) == find(v);
    }

    int find(int u){
        if(u == pai[u]) return u;
        return pai[u] = find(pai[u]);
    }

    void join(int u , int v){
        u = find(u);
        v = find(v);

        if(altura[u]>altura[v])
            swap(u,v);

        pai[u] = v;

        if(altura[u] == altura [v])
            altura[v]++;

    }

    void add_aresta(int u,int v,int custo){
        arestas.EB(u,v,custo);
    }

    vector<Aresta> Kruskal(bool maximo = false){
        clear();
        vector<Aresta> arvore;
        sort(ALL(arestas));
        if(maximo)
            reverse(ALL(arestas));

        for(auto &aresta : arestas){
            int u = aresta.u;
            int v = aresta.v;
            int custo = aresta.custo;

            if(!tem_ciclo(u,v)){
                join(u,v);

                arvore.EB(aresta);
            }
        }
    return arvore;
    }
};

int N;


int main(int argc, char** argv)
{
    optimize;
    cin >> N;
    Grafo g(N);
    for (int i = 1; i <=N ; i++) {
        int u,v,c;
        cin>>u>>v>>c;
        g.add_aresta(u,v,c);
    }

    vector<Aresta> arv_minima = g.Kruskal();
    vector<Aresta> arv_maxima = g.Kruskal(true);
    ll soma_min = 0;
    ll soma_max = 0;
    for (auto a: arv_minima)
        soma_min += a.custo;


    for(auto a : arv_maxima)
        soma_max += a.custo;
    cout<<soma_max<<endl;
    cout<<soma_min<<endl;

    return 0;
}