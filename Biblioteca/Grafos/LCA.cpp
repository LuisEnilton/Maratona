
#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>
const int MAXN = 1e6 + 5;
const int MAXL = 23;
#define INF 1000000010

vi g[MAXN];
int up[MAXN][MAXL],lvl[MAXN];
int n;
 
void dfs(int u , int p = 0, int l = 0){
    lvl[u] = l;
    up[u][0] = p;
    for(auto v : g[u]){
        if(v == p) continue;
 
        dfs(v,u,l + 1);
    }
 
}
 
 
void precalc(){
 
    for(int j = 1; j < MAXL;j++){
        for(int u = 1; u <=n;u++){
            up[u][j] = up[up[u][j - 1]][j - 1];
        }
    }
 
}
 
int lca(int a, int b){
    if(lvl[a] < lvl[b]) swap(a,b);
 
 
    for(int j = MAXL - 1;j >=0;j--){
 
        if(lvl[a] - (1 << j) >= lvl[b]){
            a = up[a][j];
        }
    }
 
    if(a == b) return a;
 
    for(int j = MAXL - 1;j >=0;j--){
 
        if(up[a][j] != up[b][j]){
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}
 
 
int query(int a , int b){
 
    auto l = lca(a,b);
 
    int dist = (lvl[a] - lvl[l]) + (lvl[b] - lvl[l]);
 
    return dist;
}
