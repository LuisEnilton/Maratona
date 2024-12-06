//
// Created by Luis on 14/11/2023.
//
#include <bits/stdc++.h>
#define ll lowng lowng
#define pii pair<int,int>
#define INF 0x3f3f3f3f
#define MAXN 10e5 + 10
using namespace std;
#define vi vector<int>
int n; // number of vertices
vector<vector<int>> grafo; // adjacency list of graph
vector<bool> vis;
vector<int> ans;
vector<int> indegree(MAXN);

void dfs(int v) {
    vis[v] = true;
    for (int u : grafo[v]) {
        if (!vis[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    vis.assign(n + 1, false);
    ans.clear();
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
}

vi khan(){
    //PRECISA CALCULAR O INDEGREE DE CADA VERTICE NA HORA DE LER AS ARESTAS

    // Coloca na fila vertices com indegree 0
    // Pra obter a ordenação topo menor possivel use priority_queue<int, vi, greater<int>
    // https://www.spoj.com/problems/TOPOSORT/
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vi result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        // Decrease indegree of adjacent vertices as the
        // current node is in topological order
        for (auto it : grafo[node]) {
            indegree[it]--;

            // If indegree becomes 0, push it to the queue
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    // Checka se tem ciclo, caso exista não existe toposort
    if (result.size() != n) {
        //cout << "Graph contains cycle!" << endl;
        return {};
    }
    return result;
}
