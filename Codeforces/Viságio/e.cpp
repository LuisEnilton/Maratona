//
// Created by Luis on 07/10/2023.
//
//Template By eduardocesb
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
const int maxn = 10e5 +2;

vi grafo[maxn];
int n;
vector<int> dijkstra(int origem){
    //fila.top () = (distancia, vertice)
    priority_queue<pii, vector<pii>, greater<pii>> fila;

    vector<int> distancias(n+10,INF);

    distancias[origem] = 0;

    fila.push({0,origem});

    vector<bool> visitados(n+10,0);

    while(!fila.empty()){
        auto [dist,atual] = fila.top();

        fila.pop();

        if(visitados[atual]) continue;

        visitados[atual] = true;

        for(auto vizinho : grafo[atual]){
            if(distancias[vizinho] > dist + 1){
                //O pai do vizinho é o atual
                distancias[vizinho] = dist + 1;
                //o msm vertice pode ser inserido mais de uma vez na fila, mas como ele já foi visitado, não será processado novamente
                fila.push({distancias[vizinho],vizinho});
            }
        }
    }
    return distancias;

}
int cnt = 0 ;
void dfs(int o){ //busca em profundidade
    queue<int> fila;
    bitset<100010> visitados;
    fila.push(o);
    while(!fila.empty()){
        int atual = fila.front();
        fila.pop();
        if(atual == n){
            if(visitados.count() == n-1){
                cnt++;
                return;
            }
            fila.push(n);
        }
        if(visitados.test(atual)) continue;
        visitados.set(atual);
        cnt++;
        for(auto x : grafo[atual]){
            fila.push(x);
        }
    }
}




int main(int argc, char** argv)
{
    optimize;
    int m;
    cin >> n >> m;
    int k; cin >> k;
    while(m--){
        int u,v;
        cin >> u >> v;
        grafo[u].EB(v);
        grafo[v].EB(u);
    }

    vi dist = dijkstra(n);
    int menor = INF;
    for(int i = 1;i < k;i++){
        menor = min(menor,dist[i]);
    }
    if(menor % 4 == 0){
        cout << max(1,menor/4) << endl;
    }else{
        cout << max(1,menor/4 + 1) << endl;
    }

    dfs(1);
    cout << (cnt - 1)/2 << endl;
    return 0;
}

