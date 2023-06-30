//
// Created by Luis on 30/06/2023.
//
//
// Created by Luis on 30/06/2023.
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
BFS : FILA (queue) distância mínima
DFS : PILHA (stack) conectividade

*/

vector<int> grafo[MAXN];
int T,I,V,A,cont=0;

void dfs(int s,vector<bool> &visited){ //busca em profundidade
    if (visited[s]) return;
    visited[s] = true;

    //cout<< s << " " << endl; //Optei por apenas imprimir o nó visitado,
    //mas, dependendo do problema, poderíamos processá-lo de outra forma.

    for (auto u: grafo[s]){ //para cada nó adjacente a s
        if(visited[u]) continue;
        cont+=2;
        dfs(u,visited);
    }
}






int main()
{
    cin>>T;
    while(T--){
        cin>>I;
        cin>>V>>A;
        cont=0;
        for(int i = 0; i < V; i++)
            grafo[i].clear();


        for (size_t i = 0; i < A; i++)
        {


            int v, w;

            cin >> v >> w ;

            grafo[v].push_back(w);
            grafo[w].push_back(v);

        }
        vector<bool> visitados(V+1, false);
        dfs(I,visitados);
        cout << cont <<endl;
    }




    return 0;
}
