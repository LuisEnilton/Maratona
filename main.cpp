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
#define vb vector<bool>
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
bool ans = true;
vector<int> arestaCor;
vector<pii> arestas;
void dfs(int u, vi &color, vector<vii > &grafo) {

    for (auto [v,id]: grafo[u]) {
        if (color[v] != -1) {
            if (color[v] == color[u])
                ans = false;
            continue;
        }
        color[v] = (color[u] == 1 ?0: 1);
        arestaCor[id] = (u == arestas[id].first ?color[u] :color[v]);
        dfs(v, color, grafo);
    }
}



void solve(int sc) {
    int n, m;
    cin >> n >> m;
    vector<vii > grafo(n + 2);
    vi color(n + 2, -1);
    arestaCor.resize(n+2);
    ans = true;
    for (int i = 0; i <m;i++) {
        int u, v;
        cin >> u >> v;
        grafo[u].EB(v,i);
        grafo[v].EB(u,i);
        arestas.EB(u,v);
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            color[i] = 1;
            dfs(i, color, grafo);
        }
    }
    if(ans){
        cout << "YES" << endl;
        for(int i=0;i<m;i++){
            cout << arestaCor[i];
        }
        cout << endl;
    }else{
        cout << "NO" << endl;
    }
}

int main() {
    optimize;
    int t;
    t = 1;
    for (int i = 1; i <= t; i++) solve(i);
    return 0;
}

