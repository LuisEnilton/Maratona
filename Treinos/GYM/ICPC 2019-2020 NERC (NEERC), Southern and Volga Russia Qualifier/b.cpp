//
// Created by Luis on 14/01/2024.
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
#define MAXN 200010
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

set<int> ans;
vector<bool> col;
vector<pii > grafo[MAXN];
pii arestas[MAXN];
vii wait;
bool dp[MAXN][2];

bool dfs(int u, int p = -1) {
    bool c = col[u];
    bool t = !c;
    for (auto [v, id]: grafo[u]) {
        if (v == p) continue;
        auto b = dfs(v, u);
        c|= b;
        t &= b;
    }
    col[u] = c;
    if (t && p != -1) {
        wait.emplace_back(u, p);
    }else{
        if(t) ans.insert(u);
    }
    return c;
}


int main() {
    optimize;
    int n, k;
    cin >> n >> k;

    col.resize(n + 2);
    for (int i = 0; i < k; i++) {
        int pos;
        cin >> pos;
        col[pos] = true;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        grafo[u].emplace_back(v, i);
        grafo[v].emplace_back(u, i);

        arestas[i] = pii(u, v);
    }
    dfs(1);
    for (int i = wait.size() - 1; i >= 0; i--) {
        auto [u,v] = wait[i];
        if(col[v]) ans.insert(u);
    }
    cout << ans.size() << endl;
    for(auto x : ans){

        cout << x << " ";
    }
    return 0;
}

/*

4 1
4
1 2
2 3
3 4
 * */