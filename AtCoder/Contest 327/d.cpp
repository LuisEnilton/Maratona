//
// Created by Luis on 04/11/2023.
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

const int maxn = 2 * 10e5 + 10;
vi grafo[maxn];
bool ans = true;
vector<bool> visited(maxn,false);
vector<bool> color(maxn);
void dfs(int u){
    visited[u] = 1;
    for(auto v : grafo[u] ){
        if(!visited[v]){
            color[v] = !color[u];
            dfs(v);
        }else{
            ans &= (color[u] != color[v]);
        }
    }
}

int main()
{
    optimize;
    int n,m; cin >> n >> m;

    vii pares(m);
    for(auto &x : pares) cin >> x.first;
    for(auto &x : pares) cin >> x.second;
    for(auto &x: pares){
        if(x.first > x.second) swap(x.first,x.second);
    }
    set<pii> duplas;
    for(auto par: pares){
        if(duplas.count(par)) continue;
        duplas.insert(par);
        auto [u,v] = par;
        if(u == v) ans = false;
        grafo[u].EB(v);
        grafo[v].EB(u);
    }
    for(int i = 1; i <=n;i++){
        if(!visited[i])
            dfs(i);
    }
    cout << (ans?"Yes":"No") << endl;
    return 0;
}

