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
#define INFLL 1000000000000000010LL
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
#define MAXN 200010
#define MAXL 23
#define EPS 1e-9
#define endl '\n'
#define int ll
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

int n, m;
vector<int> grafo[MAXN];
vector<bool> vis;
int cnt = 0;
vi comp;

void dfs(int u) {

    vis[u] = 1;
    for(auto v : grafo[u]) {
        if(vis[v]) continue;
        dfs(v);
    }
}

void solve() {
    vis.assign(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            cnt++;
            comp.PB(i);
        }
    }
}

signed main() {
    optimize;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        grafo[u].EB(v);
        grafo[v].EB(u);
    }

    solve();

    cout << cnt - 1 << endl;
    for (int i = 1; i < comp.size(); i++) {
        cout << comp[i - 1] << " " << comp[i] << endl;
    }
    return 0;
}

// 1 2 3 4 5
// 2 5 1 4 3 - 11
// 3 5 2 4 1 -

// 1 2 3 2 3 4 3 1 4
