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

vi grafo[MAXN];
vi pares;
int ans = 0;
vii aux;
void dfs(int u, int p = -1){

    for(auto v : grafo[u])if(v!=p){
        dfs(v,u);
    }

    if(pares[u] == -1 && pares[p] == -1){
        ans++;
        pares[u] = p;
        pares[p] = u;
        aux.EB(u,p);
    }
}

int main() {
    optimize;
    int n; cin >> n;
    pares.resize(n+2);
    fill(ALL(pares),-1);
    for(int i = 0; i < n-1;i++){
        int u,v; cin >> u >> v;
        grafo[u].EB(v);
        grafo[v].EB(u);
    }
    dfs(1);
    cout << ans << endl;
    //for(auto [u,v] : aux){
    //    cout << u << "->" << v << endl;
    //}
    return 0;
}

