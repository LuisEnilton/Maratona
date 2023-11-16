#include <bits/stdc++.h>
#define ll lowng lowng
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pii pair<int,int>
#define EB emplace_back
const int MAXN = 1e6 + 5;
using namespace std;


// Centro de arvore
//
// Retorna o diametro e o(s) centro(s) da arvore
// Uma arvore tem sempre um ou dois centros e estes estao no meio do diametro
//
// O(n)

vector<int> g[MAXN];
int d[MAXN], par[MAXN];

//1 - Indexado
pair<int, vector<int>> center(vector<vi > &grafo) {
    int f, df;
    int n = grafo.size();
    vi d(n + 1), par(n + 1);
    function<void(int)> dfs = [&](int v) {
        if (d[v] > df) f = v, df = d[v];
        for (int u: grafo[v])
            if (u != par[v])
                d[u] = d[v] + 1, par[u] = v, dfs(u);
    };

    f = df = par[1] = -1, d[1] = 0;
    dfs(1);
    int root = f;
    f = df = par[root] = -1, d[root] = 0;
    dfs(root);

    vector<int> c;
    while (f != -1) {
        if (d[f] == df / 2 or d[f] == (df + 1) / 2) c.push_back(f);
        f = par[f];
    }

    return {df, c};
}

int main() {
    int n, m;
    cin >> n;
    vector<vi > grafo(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        grafo[u].EB(v);
        grafo[v].EB(u);
    }
    auto ans = center(grafo);
    cout << "Diametro: " << ans.first << endl;
    for(auto x : ans.second){
        cout << "Centro: " << x << endl;
    }
    return 0;
}