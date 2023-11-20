//
// Created by Luis on 17/11/2023.
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

struct DSU{
    vector<int> pai;
    vector<int> altura;

    DSU(int n){
        pai.resize(n+1);
        altura.resize(n+1);
        resetDSU(n);
    }

    inline void resetDSU(int &n){
        for(int i=0; i<=n; i++)
            altura[i] = 1, pai[i] = i;
    }

    inline int find(int u){
        return ( pai[u] == u  ?  u  :  pai[u] = find(pai[u]) );
    }

    void join(int u,int v){
        u = find(u);
        v = find(v);
        if(u == v)  return;
        //compressão de altura
        if(altura[u] > altura[v]){
            swap(u,v);
        }
        pai[u] = v;

        if(altura[u] == altura[v]) altura[v]++;

    }
};


int main()
{
    optimize;
    int n,q; cin >> n >> q;
    auto dsu = DSU(n);
    while(q--){
        int op; cin >> op;
        if(op == 0){
            int u,v; cin >> u >> v;
            dsu.join(u,v);
        }else{
            int u,v; cin >> u >> v;
            cout <<(dsu.find(u) == dsu.find(v)) << endl;
        }
    }
    return 0;
}

