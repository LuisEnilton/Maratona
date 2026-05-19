//
// Created by Luis on 06/09/2023.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define optimize ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define MAXN 1010101
#define int ll
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'

using namespace std;

struct DSU{
    vector<int> pai;
    vector<int> sz;

    DSU(int n){
        pai.resize(n+1);
        sz.resize(n+1);
        resetDSU(n);
    }

    inline void resetDSU(int &n){
        for(int i=0; i<=n; i++)
            sz[i] = 1, pai[i] = i;
    }

    inline int find(int u){
        return ( pai[u] == u  ?  u  :  pai[u] = find(pai[u]) );
    }

    inline void join(int u, int v){
        u = find(u);
        v = find(v);

        if(u == v) return;
        if(sz[v] > sz[u]) swap(u, v);

        pai[v] = u;
        sz[u] += sz[v];
    }
};

signed main() {
    optimize;
    int n,m; cin >> n >> m;

    map<int,vii> arestas;

    while(m--){
        int u,v,w; cin >> u >> v >> w;
        arestas[w].emplace_back(u,v);
    }
    map<int,int> low,pre; // mais baixo que apareceu e quando apareceu
    int clk = 0;
    // id da aresta que ele veio
    function<int(int,map<int,vii>&,map<int,bool> & vis ,int)> tarjan = [&](int u, map<int,vii> &g,map<int,bool> & vis,int pid = -1){
        // dbg(u);
        pre[u] = low[u] = clk++;
        vis[u] = 1;
        int ans = 0;
        // dbg(g[u].size());
        for(auto [v,id] : g[u]){
            if(pid == id) continue;
            // dbg(v);
            if(!pre.count(v)){
                ans += tarjan(v,g,vis,id);
                // dbg(low[v]);
                // dbg(pre[u]);
                low[u] = min(low[v], low[u]);
                if(low[v] > pre[u]) ans++;

            }else{
                low[u] = min(low[u],pre[v]);
            }

        }
        return ans;
    };

    auto dsu = DSU(n + 1);
    dsu.resetDSU(n);
    int resp = 0;
    for(auto &[k,are] : arestas){
        // dbg(k);
        low.clear();
        pre.clear();
        clk = 0;
        map<int,vii> g;
        map<int,bool> vis;
        int id = 0;
        for(auto [u,v] : are){

            u = dsu.find(u);
            v = dsu.find(v);
            if(u == v) continue;
            g[u].emplace_back(v,id);
            g[v].emplace_back(u,id);
            id++;
        }

        int ans = 0;
        
        for(auto &[u,sla] : g){
            if(vis[u]) continue;

            ans += tarjan(u,g,vis,-1);

        }
        // arestas que são pontes não são pesadas
        int curr = are.size() - ans; 
        // dbg(curr);
        resp += curr;

        for(auto [u,v] : are){
            dsu.join(u,v);
        }

    }
    cout << resp << endl;


    return 0;
}

