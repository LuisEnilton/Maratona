//
// Created by Luis on 06/09/2023.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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


int pai[MAXN], sz[MAXN],xp[MAXN];

int find(int u){
    return (u == pai[u]?u:pai[u] = find(pai[u]));
}


void join(int u, int v){
    u = find(u),v = find(v);
    if(u == v) return;

    if(sz[u] < sz[v]) swap(u,v);

    sz[u]+=sz[v];
    pai[v] = u;
}

void resetDSU(int &n){
    for(int i = 0 ; i <=n;i++){
        pai[i]   = i,sz[i] = 1,xp[i] = 0;
    }
}


int main() {
    optimize;
    int n, m; cin >> n >> m;
    resetDSU(n);
    while(m--){
        string op; cin >> op;
        
        if(op == "join"){
            int u,v; cin >> u >> v;
            join(u,v);
        }

        if(op == "add"){

        }

        if(op == "get"){
            int u; cin >> u;
        }
    }
    return 0;
}
