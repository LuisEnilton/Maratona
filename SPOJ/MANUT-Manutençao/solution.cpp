//
// Created by Luis on 14/11/2023.
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


vector<vector<int>> grafo;
vi cut, pre, low;
int clk;

void dfs(int u, int pai) {
    pre[u] = low[u] = clk++;
    bool any = false;
    int chd = 0;
    for (auto v: grafo[u]) {
        if (v == pai) continue;
        //Se o vertice não foi visitado
        if (pre[v] == -1) {
            dfs(v, u);
            //O mais longe que aquela componente consegue chegar
            low[u] = min(low[u], low[v]);

            //Se aquela componente n consegue se conectar sem U
            if (low[v] >= pre[u]) any = true;

            chd++;
        } else {
            low[u] = min(low[u], pre[v]);
        }
    }

    if(pai == -1 && chd>=2) cut.push_back(u);
    //Se qualquer componente n consegue se conectar com o resto do grafo sem U => U é um vertice de corte
    if(pai!= -1 && any) cut.push_back(u);

}


void find_vert(int &n) {
    cut.clear();
    pre.clear();
    pre.resize(n + 1);
    low.clear();
    low.resize(n + 1);
    clk = 0;
    fill(ALL(pre), -1);

    dfs(1, -1);
}


int main() {
    optimize;
    int n, m;
    int t = 1;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        cout << "Teste " << t << endl;
        grafo.clear();
        grafo.resize(n + 1);
        while (m--) {
            int u, v;
            cin >> u >> v;
            grafo[u].EB(v);
            grafo[v].EB(u);
        }
        find_vert(n);
        if(cut.size() == 0){
            cout << "nenhum";
        }else{
            sort(ALL(cut));
            for(auto vertCort: cut){
                cout << vertCort << " ";
            }
        }
        cout << endl;
        cout << endl;
        t++;
    }
    return 0;
}

