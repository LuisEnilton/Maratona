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
#define MAXN 1010
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
int N, M;
int cont = 0;










//Para virar dfs é só trocar a fila por uma pilha
void busca(int origem,vector<bool> &visitados){
    cont++;
    stack<int> pilha;

    pilha.push(origem);



    while(!pilha.empty()){
        int atual = pilha.top();

        pilha.pop();

        if(visitados[atual]){
            continue; //não processa o msm cara 2 vezes

        }

        visitados[atual] = true;
        /*
         calcula o que precisa

        */

        for (auto proximo: grafo[atual])
        {
            if(!visitados[proximo]){
                pilha.push(proximo);
            }
        }

    }

}


int solve(){
    vector<bool> visitados(N+1, false);
    for(int i = 1;i<=N+1;i++) {
        if(visitados[i]) continue;
        busca(i, visitados);
    }

    return cont;
}



int main()
{
    cin>>N>>M;
    for(int i =1;i<=M;i++){
        int u,v;
        cin>>u>>v;
        grafo[u].emplace_back(v);
        grafo[v].emplace_back(u);

    }
        cout<<solve() - 1<<endl;



    return 0;
}
