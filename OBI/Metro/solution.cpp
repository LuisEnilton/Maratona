//
// Created by Luis on 15/11/2023.
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
#define MAXN 20010
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>
vector<int> grafo[MAXN];
int val,cnt = 0,ans,searching = -1;
int marked = -1;
vector<bool> visited;
void dfs(int u, int pai){
    cnt++;
    if(visited[u] && grafo[u].size() < 5){
        searching = u;
        marked = pai;
        val = cnt;
    }
    if(visited[u] || grafo[u].size() >=5) {
        cnt--;
        return;
    }
    visited[u] = true;
    for(auto v : grafo[u]){
        if(v == pai || v == marked) continue;
        dfs(v,u);
    }
    if(u == searching){
        ans = val - cnt;
    }
    cnt--;
}



int main()
{
    optimize;
    int n,m; cin >> n >> m;
    visited.resize(n+1);
    while(m--){
        int u,v; cin >> u >> v;
        grafo[u].EB(v);
        grafo[v].EB(u);
    }
    //dfs(1,-1);
    for(int i = 1; i <=n;i++){
        if(grafo[i].size() <5 && grafo[i].size() >=2){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

