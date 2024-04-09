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
#define vb vector<bool>
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

int n,m;
vi grafo[MAXN];

vi color;
bool ans = true;
void dfs(int u,int p = -1){

    for(auto v : grafo[u]){
        if(v == p) continue;
        if(color[v] != -1  ){
            if(color[v] == color[u])
                ans = false;
            continue;
        }
        color[v] = (color[u] == 1?2:1);
        dfs(v,u);

    }
}

int main() {
    optimize;
    cin >> n >> m;
    color.resize(n+1);
    fill(ALL(color),-1);
    while(m--){
        int u,v; cin >> u >> v;
        grafo[u].EB(v);
        grafo[v].EB(u);
    }
    for(int i = 1; i <=n;i++){
        if(color[i] == -1){
            color[i] = 1;
            dfs(i);
        }
    }
    if(ans){
        for(int i = 1; i <=n;i++){
            cout << color[i] << " ";
        }
        cout << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}

