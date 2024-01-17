//
// Created by Luis on 16/01/2024.
//
//Feito por SamuellH12
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 5;
const int MAXLG = 16;

vector<int> grafo[MAXN];

int bl[MAXLG][MAXN], lvl[MAXN];
int N;


void dfs(int u, int p = -1, int l = 0) {
    lvl[u] = l;
    bl[0][u] = p;

    for (auto v: grafo[u])
        if (v != p)
            dfs(v, u, l + 1);
}


void buildBL() {
    for (int i = 1; i < MAXLG; i++)
        for (int u = 1; u <= N; u++)
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
    return (lvl[l] - lvl[u]) + (lvl[l] - lvl[v]);
}

int main() {
    optimize;
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        cout << "Case " << k << ": " << endl;
        int n;
        cin >> n;
        N = n;
        for (int i = 1; i <= n; i++) grafo[i].clear();
        for (int i = 1; i <= n; i++) {
            int q;
            cin >> q;
            while (q--) {
                int v;
                cin >> v;
                grafo[i].emplace_back(v);
                grafo[v].emplace_back(i);
            }
        }
        precalc();
        int q;
        cin >> q;

        while (q--) {
            int u, v;
            cin >> u >> v;
            cout << lca(u, v) << endl;
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
