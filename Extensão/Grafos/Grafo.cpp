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
vector<int> grafo_rev[MAXN];
int N, M;



bool busca2(int i){
    queue<int> fila;
    fila.push(1);

    vector<bool> visitados(N+1, 0);

    while(!fila.empty()){
        int atual = fila.front();
        if(atual == i)
            return true;
        fila.pop();
        
        if(visitados[atual] ){
            continue; //não processa o msm cara 2 vezes

        }

        visitados[atual] = true;
        /*
         calcula o que precisa
        
        */

        for (auto proximo: grafo_rev[atual])
        {
            if(!visitados[proximo]){
                fila.push(proximo);
            }
        }
        
    }



}


//Para virar dfs é só trocar a fila por uma pilha
void busca(int origem,vector<bool> &visitados){
    queue<int> fila;

    fila.push(origem);
    


    while(!fila.empty()){
        int atual = fila.front();
        
        fila.pop();
        
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
                fila.push(proximo);
            }
        }
        
    }

}


bool solve(){
    vector<bool> visitados(N+1, 0);
        busca(1,visitados);

        for (size_t j = 1; j <=N; j++)
        {
            if(visitados[j] == false)
                return false;
        }
    
    for (size_t i = 2; i <= N; i++)
    {
        
        if(!busca2(i))
            return false;
        
        
    }

    return true;
}



int main()
{
    while((cin >> N >> M) && (N!=0 || M!=0)){
        
        for(int i = 1; i <= N; i++){
            grafo[i].clear();
            grafo_rev[i].clear();
        }
        
        for (size_t i = 0; i < M; i++)
        {
            
            
            int v, w, p;
            
            cin >> v >> w >> p;

            if (p == 1)
            {
                grafo[v].push_back(w);
                grafo_rev[w].push_back(v);
            }
            else
            {
                grafo[v].push_back(w);
                grafo[w].push_back(v);
                grafo_rev[v].push_back(w);
                grafo_rev[w].push_back(v);
            }
        }
        cout << solve() <<endl;
    }

    


    return 0;
}
