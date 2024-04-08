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




vi grafo[MAXN];
vi rev[MAXN];
int n,m;

void print(int u,int v){
    cout << "NO" << endl;
    cout << u << " " << v << endl;
}

void dfs(int u,vector<bool> &visited){
    if(visited[u]) return;
    visited[u] = 1;
    for(auto v : grafo[u]){
        dfs(v,visited);
    }
}

void dfs2(int u,vector<bool> &visited){
    //cout << u << " " << visited[u] << endl;
    if(visited[u]) return;
    visited[u] = 1;
    for(auto v : rev[u]){
        //cout << "v: " << v << endl;
        dfs2(v,visited);
    }
}

void solve(){
    vector<bool> visited(n + 1,false);
    dfs(1,visited);
    for(int i = 1; i <=n;i++){
        if(!visited[i]){
            print(1,i);
            return;
        }
        visited[i] = false;
    }
    dfs2(1,visited);
    for(int i = 1; i <=n;i++){
        if(!visited[i]){
            print(i,1);
            return;

        }
    }
    cout << "YES" << endl;
}
int main() {
    optimize;
    cin >> n >> m;
    while(m--){
        int u,v; cin >> u >> v;
        grafo[u].PB(v);
        rev[v].PB(u);
    }
    solve();
    return 0;
}

