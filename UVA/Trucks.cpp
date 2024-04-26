//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cmath>
#define int long long
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
#define MAXLG 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

int sz[MAXN],pai[MAXN];
vii grafo[MAXN],grafo2[MAXN];
int n,m;

int find(int u){
    return (u == pai[u] ? u : pai[u] = find(pai[u]));
}

void join(int u,int v){
    u = find(u),v = find(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u,v);

    pai[v] = u;
    sz[u] += sz[v];
}

void resetDSU(){
    for(int i = 0; i < MAXN;i++){
        sz[i] = 1,pai[i] = i;
    }
}


struct Aresta{
    int u, v, c;
    Aresta(int u,int v,int c) : u(u),v(v),c(c){}
};

bool compAresta(Aresta a, Aresta b){ return a.c < b.c; }

vector<Aresta> arestas; 			//Lista de Arestas



int kruskal(){
    sort(ALL(arestas), compAresta);	//Ordena pelo custo
    reverse(ALL(arestas));
    int resp = 0;					//Custo total da MST

    for(auto a : arestas)
        if( find(a.u) != find(a.v) )
        {
            resp += a.c;
            join(a.u, a.v);
            grafo2[a.u].EB(a.v,a.c);
            grafo2[a.v].EB(a.u,a.c);
        }

    return resp;
}

int bl[MAXLG][MAXN], lvl[MAXN], dp1[MAXLG][MAXN], dp2[MAXLG][MAXN];
int val[MAXN]; // Cada filho guarda o valor da aresta que vai pro pai

void dfs(int u, int p = -1, int l = 0) {
    lvl[u] = l;
    bl[0][u] = p;

    for (auto [v, c]: grafo2[u])
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
        }
}

void precalc() {
    memset(bl,-1,sizeof bl);
    memset(dp1,0,sizeof dp1);
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

int query(int a, int b){
    auto l = lca(a,b);

    int mini = INF;
    int k = lvl[b] - lvl[l];
    int u = b;
    for(int i = MAXLG - 1;i>=0;i--){
        if( k  & (1 << i) && u!= -1){
            mini = min(mini,dp1[i][u]);
            u = bl[i][u];
        }
    }
    k = lvl[a] - lvl[l];
    u = a;
    for(int i = MAXLG - 1;i>=0;i--){
        if( k  & (1 << i) && u!= -1){
            mini = min(mini,dp1[i][u]);
            u = bl[i][u];
        }
    }
    return mini;
}

signed main() {
    //optimize;
    int s;
    while(cin >> n >> m >> s){
        for(int i = 1 ; i <=n;i++) {
            grafo[i].clear();
            grafo2[i].clear();
        }
        resetDSU();
        arestas.clear();


        while(m--){
            int u,v,c; cin >> u >> v >> c;
            grafo[u].EB(v,c);
            grafo[v].EB(u,c);

            arestas.EB(u,v,c);
        }

        kruskal();
        precalc();

        while(s--){
            int a,b; cin >> a >> b;
            cout << query(a,b) << endl;
        }
    }

    return 0;
}

