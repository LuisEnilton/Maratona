//
// Created by Luis on 16/01/2024.
//
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
#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

const int MAX = 2 * 10e5 + 10;

vi grafo[MAX];
int ps[MAX];
int pai[MAX];
vi val;
int sum = 0, t = 0;
int sz[MAX];
int pos[MAX];

void dfs(int u, int p = -1) {
    pai[u] = p;
    sz[u] = 1;
    sum += val[u];
    pos[u] = t;
    ps[t++] = sum;
    for (auto v: grafo[u])
        if (v != p) {
            dfs(v, u);
            sz[u] += sz[v];
            
        }
}

void solve() {
    dfs(1);
}

int query(int u) {
    int ans = 0;
    for (auto v: grafo[u]) {
        if (v == pai[u]) {
            ans += (ps[pos[v] + sz[v]] - ps[pos[v]]) - (ps[pos[u] + sz[u]] - ps[pos[u]]);
        } else {
            ans += ps[pos[v] + sz[v]] - ps[pos[v]];
        }
    }

}

int main() {
    //optimize;
    int n, k;
    cin >> n >> k;
    val.resize(n + 2);

    for (int i = 0; i < k; i++) {
        int p;
        cin >> p;
        val[p] = 1;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        grafo[u].EB(v);
        grafo[v].EB(u);
    }
    solve();
    set<int> ans;
    for (int i = 1; i <= n; i++) {
        if (val[i]) continue;
        auto a = query(i);
        if (a == k) ans.insert(i);
    }
    cout << ans.size() << endl;
    for (auto x: ans) cout << x << " ";
    cout << endl;
    return 0;
}

/*
 4 1
3
1 4
2 3
2 4
 * */

