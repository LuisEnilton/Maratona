//
// Created by Luis on 16/01/2024.
//
//
// Created by Luis on 16/01/2024.
//
//Feito por SamuellH12

#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

const int MAXN = 2 * 10e5 + 3;
const int MAXLG = 23;

vector<int> grafo[MAXN];

int bl[MAXLG][MAXN], lvl[MAXN];
int n;


void dfs(int u, int p = -1, int l = 0) {
    lvl[u] = l;
    bl[0][u] = p;

    for (auto v: grafo[u])
        if (v != p)
            dfs(v, u, l + 1);
}


void buildBL() {
    for (int i = 1; i < MAXLG; i++)
        for (int u = 1; u <= n; u++)
            bl[i][u] = bl[i - 1][bl[i - 1][u]];
}

void precalc() {
    dfs(1);
    buildBL();
}

int lca(int u, int v) {
    if (lvl[u] < lvl[v]) swap(u, v);

    for (int i = MAXLG - 1; i >= 0; i--)
        if (lvl[u] - (1 << i) >= lvl[v])
            u = bl[i][u];

    if (u == v) return u;

    for (int i = MAXLG - 1; i >= 0; i--)
        if (bl[i][u] != bl[i][v])
            u = bl[i][u],
                    v = bl[i][v];

    return bl[0][u];
}

int dist(int u, int v) {
    auto l = lca(u, v);
    return lvl[u] + lvl[v] - 2*lvl[l];
}

int main() {
    optimize;
    int q; cin >> n >> q;
   for(int i = 0; i < n-1;i++) {
       int u,v; cin >> u >> v;
       grafo[u].emplace_back(v);
       grafo[v].emplace_back(u);
   }
        precalc();
        while (q--) {
            int u, v;
            cin >> u >> v;
            auto ans =dist(u,v);
            cout << ans << endl;



    }
    return 0;
}

