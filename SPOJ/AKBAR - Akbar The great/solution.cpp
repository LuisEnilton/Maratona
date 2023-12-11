//
// Created by Luis on 18/11/2023.
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
#define MAXN 1000101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

vector<vi > grafo;
int cnt = 0;
vector<int> st;
vector<bool> visited;
bool ok = true;

void bfs(int &o, int &s) {
    queue<int> fila;

    st[o] = s;

    fila.push(o);

    while (!fila.empty()) {
        auto u = fila.front();
        fila.pop();
        if (visited[u]) {
            ok = false;
            break;
        }
        visited[u] = true;
        for (auto v: grafo[u]) {
            if (st[u] - 1 > st[v]) {
                st[v] = st[u] - 1;
                fila.push(v);
            }
        }
    }
}

void solve() {
    int n, r, m;
    cin >> n >> r >> m;
    grafo.clear();
    grafo.resize(n + 1);
    st.clear();
    st.resize(n + 1);
    visited.clear();
    visited.resize(n + 1);
    fill(ALL(st), -1);
    ok = true;
    cnt = 0;

    while (r--) {
        int u, v;
        cin >> u >> v;
        grafo[u].EB(v);
        grafo[v].EB(u);
    }

    vii lista;
    while (m--) {
        int k, s;
        cin >> k >> s;
        lista.EB(k, s);
    }

    for (auto [k, s]: lista) {
        bfs(k, s);
        if (!ok) break;
    }
    for (int i = 1; i <= n; i++) {
        ok &= visited[i];
    }
    cout << (ok ? "Yes" : "No") << endl;
}

int main() {
    optimize;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

