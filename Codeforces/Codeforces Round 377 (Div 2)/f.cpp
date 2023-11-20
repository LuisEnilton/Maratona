#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e6 + 5;
using namespace std;

int pai[MAXN], sz[MAXN];


inline int find(int u){  return ( pai[u] == u  ?  u  :  pai[u] = find(pai[u]) );  }

inline void join(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return;
    if(sz[v] > sz[u]) swap(u, v);

    pai[v] = u;
    sz[u] += sz[v];
}

inline void resetDSU(){
    for(int i=0; i<MAXN; i++)
        sz[i] = 1, pai[i] = i;
}

pii arestas[MAXN];
bool dir[MAXN];

vector<pii> grafo[MAXN];
vector<pii> trafo[MAXN];


int pre[MAXN], low[MAXN], clk=0;

vi pontes;

void tarjan(int u, int p = -1)
{
    pre[u] = low[u] = clk++;

    for(auto [v, id] : grafo[u])
    {
        if(v == p) continue;

        if(pre[v] == -1)
        {
            tarjan(v, u);

            low[u] = min(low[v], low[u]);

            if(low[v] >  pre[u]) pontes.emplace_back(id);
            else join(u, v);

            dir[id] = ( u == arestas[id].first ? 0 : 1 );
        }
        else{
            low[u] = min(low[u], pre[v]);
            if(pre[u] > pre[v])
                dir[id] = ( u == arestas[id].first ? 0 : 1 );
        }
    }

}
map<pii,pii> conv;
void dfs(int u, int p){

    for(auto [v, id] : trafo[u])
    {
        if(v == p) continue;
        auto [o,d] =  conv[{u,v}];
        dir[id] = (o == arestas[id].first ? 0 : 1);
        dfs(v, u);
    }

}


int main(){
    optimize;
    memset(pre, -1, sizeof pre);

    int n, m;
    cin >> n >> m;


    for(int i=0, u, v; i<m; i++){
        cin >> u >> v;

        grafo[u].emplace_back(v, i);
        grafo[v].emplace_back(u, i);

        arestas[i] = pii(u, v);
    }

    resetDSU();
    tarjan(1);

    //cerr << pontes.size() << endl;

    int ans = 0, st=-1;

    for(auto id : pontes){
        auto [u, v] = arestas[id];
        int pu = find(u);
        int pv = find(v);

        trafo[pu].emplace_back(pv, id);
        trafo[pv].emplace_back(pu, id);
        conv[{pu,pv}] = {u,v};
        conv[{pv,pu}] = {v,u};
        if(sz[pu] > ans) ans = sz[pu], st=pu;
        if(sz[pv] > ans) ans = sz[pv], st=pv;
    }

    if(st != -1) dfs(st, -1);
    else ans = n;


    cout << ans << endl;

    for(int i=0; i<m; i++)
    {
        if(dir[i]) cout << arestas[i].first << " " << arestas[i].second << endl;
        else cout << arestas[i].second << " " << arestas[i].first << endl;
    }


    return 0;
}