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
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

int sz[MAXN],pai[MAXN];
vi grafo[MAXN];
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

	int resp = 0;					//Custo total da MST

	for(auto a : arestas)
		if( find(a.u) != find(a.v) )
		{
			resp += a.c;
			join(a.u, a.v);
		}

	return resp;
}

void dfs(int u, vector<bool> &v){
    if(v[u]) return;
    v[u] = true;
    for(auto x : grafo[u])
        dfs(x,v);
}

bool check(){
    vector<bool> v(n + 2);
    dfs(1,v);
    for(int i = 1; i <=n;i++){
        if(!v[i]) return false;
    }
    return true;
}

signed main() {
    optimize;
    resetDSU();
    cin >> n >> m; 
    while(m--){
        int u,v,c; cin >> u >> v >> c;
        grafo[u].PB(v);
        grafo[v].PB(u);
        
        arestas.EB(u,v,c);
    }
    if(check()){
        cout << kruskal() << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}

