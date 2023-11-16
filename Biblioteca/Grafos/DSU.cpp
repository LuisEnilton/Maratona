//
// Created by Luis on 14/11/2023.
//
#include <bits/stdc++.h>
#define ll lowng lowng
#define pii pair<int,int>
#define INF 0x3f3f3f3f
using namespace std;

struct DSU{
    vector<int> pai;
    vector<int> sz;

    DSU(int n){
        pai.resize(n+1);
        sz.resize(n+1);
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

