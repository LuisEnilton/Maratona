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
#define MAXN 50010
#define MAXL 20
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

vi grafo[MAXN];
int lvl[MAXN];
int ancestral[MAXL][MAXN];
int n;

void dfs(int u, int p = -1) {
    if (p != -1) lvl[u] = lvl[p] + 1;

    for (auto v: grafo[u])
        if (v != p) {
            ancestral[0][v] = u;
            dfs(v, u);
        }
}

void precalc() {
    memset(ancestral,-1,sizeof ancestral);
    dfs(1);
    for (int i = 1; i < MAXL; i++) {
        for (int j = 1; j <= n; j++) {
            ancestral[i][j] = ancestral[i - 1][ancestral[i - 1][j]];
        }
    }
}

int lca(int a, int b) {
    if (lvl[a] < lvl[b]) swap(a, b);

    for (int i = MAXL - 1; i >= 0; i--) {
        if (lvl[a] - (1 << i) >= lvl[b]) {
            a = ancestral[i][a];
        }
    }

    if (a == b) return a;

    for (int i = MAXL - 1; i >= 0; i--) {
        if (ancestral[i][a] != ancestral[i][b]) {
            a = ancestral[i][a];
            b = ancestral[i][b];
        }
    }
    return ancestral[0][b];
}

int dist(int a, int b) {
    auto l = lca(a, b);
    return abs(lvl[a] - lvl[l]) + abs(lvl[b] - lvl[l]);
}

int main() {
    optimize;
    cin >> n;
    vector<vi > pares(n);
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        pares[num].push_back(i);
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        grafo[u].EB(v);
        grafo[v].EB(u);
    }
    precalc();
    ll ans = 0;
    for (int i = 1; i <=n/2;i++) {
        int a = pares[i][0], b = pares[i][1];
        ans += dist(a, b);
    }
    cout << ans << endl;
    return 0;
}

