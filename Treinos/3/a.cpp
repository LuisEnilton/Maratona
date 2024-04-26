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
#define vb vector<bool>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101
#define MAXN 1010101
#define MAXLG 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

int bl[MAXLG][MAXN], lvl[MAXN];
ll dist[MAXN]; // dist até a raiz
int n;
int val[MAXN]; // Cada filho guarda o valor da aresta que vai pro pai
vector<pair<int ,ll>> grafo[MAXN];


void dfs(int u, int p = -1, int l = 0) {
    lvl[u] = l;
    bl[0][u] = p;

    for (auto [v, c]: grafo[u])
        if (v != p) {
            dist[v] = dist[u]  + c;
            dfs(v, u, l + 1);
        }
}


void buildBL() {
    for (int i = 1; i < MAXLG; i++)
        for (int u = 1; u <= n; u++) {
            bl[i][u] = bl[i - 1][bl[i - 1][u]];
        }
}

void precalc() {
    memset(bl,-1,sizeof bl);
    dfs(1);
    dist[1] = 0;
    buildBL();
}

int lca(int u, int v) {
    if (lvl[u] < lvl[v]) swap(u, v);

    for (int i = MAXLG - 1; i >= 0; i--)
        if (lvl[u] - (1 << i) >= lvl[v])
            u = bl[i][u];

    if (u == v) return u;

    for (int i = MAXLG - 1; i >= 0; i--)
        if (bl[i][u] != bl[i][v]){
            u = bl[i][u],
            v = bl[i][v];
        }

    return bl[0][u];
}

ll query(int a, int b){
    auto l = lca(a,b);
    auto ans = (dist[a] - dist[l]) + (dist[b] - dist[l] ) ;
    return ans;
}

int main() {
    optimize;
    cin >> n;
    for(int i = 0 ; i < n-1;i++){
        int u,v; cin >> u >> v;
        ll z; cin >> z;
        grafo[u].EB(v,z);
        grafo[v].EB(u,z);

    }
    precalc();
    int q; cin >> q;
    while(q--){
        int a,b,c; cin >> a >> b >> c;
        ll ans = query(a,b);
        ans+= query(b,c);
        cout << ans << endl;
    }
    return 0;
}

