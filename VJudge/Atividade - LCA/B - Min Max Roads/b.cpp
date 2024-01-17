//
// Created by Luis on 16/01/2024.
//
//Feito por SamuellH12

#include <bits/stdc++.h>
#define MAXN  100010
#define MAXLG  20
using namespace std;
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 1000000010

vector<pair<int, int>> grafo[MAXN];

int bl[MAXLG][MAXN], lvl[MAXN], dp1[MAXLG][MAXN], dp2[MAXLG][MAXN];
int n;

void dfs(int u, int p = -1, int l = 0) {
    lvl[u] = l;
    bl[0][u] = p;

    for (auto [v, c]: grafo[u])
        if (v != p) {
            dp1[0][v] = c;
            dp2[0][v] = c;
            dfs(v, u, l + 1);
        }
}


void buildBL() {
    for (int i = 1; i < MAXLG; i++)
        for (int u = 1; u <= n; u++) {
            bl[i][u] = bl[i - 1][bl[i - 1][u]];
            dp1[i][u] = min(dp1[i - 1][bl[i - 1][u]], dp1[i - 1][u]);
            dp2[i][u] = max(dp2[i - 1][bl[i - 1][u]], dp2[i - 1][u]);
        }
}

void precalc() {
    memset(bl, -1, sizeof bl);
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




pair<int, int> query(int a, int b) {
    pair<int, int> ans;
    auto l = lca(a, b);
    auto k = lvl[a] - lvl[l];
    int mini = INF, maxi = 0;
    int u = a;
    for (int i = MAXLG - 1; i >= 0; i--) {
        if (k & (1 << i) && u != -1) {
            mini = min(mini, dp1[i][u]);
            maxi = max(maxi, dp2[i][u]);
            u = bl[i][u];
        }
    }

    k = lvl[b] - lvl[l];
    u = b;
    for (int i = MAXLG - 1; i >= 0; i--) {
        if (k & (1 << i) && u != -1) {
            mini = min(mini, dp1[i][u]);
            maxi = max(maxi, dp2[i][u]);
            u = bl[i][u];
        }
    }
    return make_pair(mini, maxi);
}


int main() {
    optimize;
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        cout << "Case " << k << ":" << endl;
        //cout << endl;
        cin >> n;
        for (int i = 1; i <= n; i++) grafo[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            grafo[u].emplace_back(v, c);
            grafo[v].emplace_back(u, c);
        }
        precalc();
        int q;
        cin >> q;
        while (q--) {
            int x, y;
            cin >> x >> y;
            auto ans = query(x, y);
            cout << ans.first << " " << ans.second << endl;
        }
    }
    return 0;
}


/**************************************
Algoritmo para encontrar o menor ancestral
comum entre dois vértices U e V em uma árvore
enraizada

Complexity:
dfs()     ->  O(V+E)
buildBL() ->  O(N Log N)
lca() 	  ->  O(Log N)


* Informações
	-> Monte o grafo na lista de adjacências
	-> chame dfs(root, root) para calcular o pai e a altura de cada vértice
	-> chame buildBL() para criar a matriz do Binary Lifting
	-> chame lca(u, v) para encontrar o menor ancestral comum

	bl[i][u] -> Binary Lifting com o (2^i)-ésimo pai de u
	lvl[u]   -> Altura ou level de U na árvore

* Em LCA o primeiro FOR iguala a altura de U e V
* E o segundo anda até o primeiro vértice de U que não é ancestral de V
* A resposta é o pai desse vértice


IMPORTANTE! O algoritmo está 0-indexado

**************************************/
