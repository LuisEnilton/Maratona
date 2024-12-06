//
// Created by Luis on 06/09/2023.
//
// Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 1000000010
#define vi vector<int>
#define vb vector<bool>
#define PB push_back
#define EB emplace_back
#define MAXN 200010

#define endl '\n'
using namespace std;

int n, m;
vi grafo[MAXN];
vb vis;
vi pai;
int cycle_start, cycle_end;

bool dfs(int u, int p = -1) {
    vis[u] = true;
    for (int v : grafo[u]) {
        if(v == p) continue;
        if (vis[v]) {
            cycle_end = u;
            cycle_start = v;
            return true;
        }
        pai[v] = u;
        if (dfs(v, pai[v]))
            return true;
    }
    return false;
}

void find_cycle() {
    vis.assign(n + 1, false);
    pai.assign(n + 1, -1);
    cycle_start = -1;

    for (int i = 1; i <= n; i++) {
        if (!vis[i] && dfs(i))
            break;
    }

}

signed main() {
    optimize;
    // https://cses.fi/problemset/task/1669
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        grafo[u].EB(v);
        grafo[v].EB(u);
    }

    find_cycle();

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vi cycle;
        int cnt = 1;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = pai[v]) {
            cycle.push_back(v);
            cnt++;
        }
        cycle.push_back(cycle_start);
        cnt++;
        cout << cnt << endl;
        for (int u : cycle)
            cout << u << " ";
        cout << endl;
    }

    return 0;
}