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
vector<int> sz;
int dfs(int u, int p = -1){
    sz[u] = 0;
    for(auto v : grafo[u]) if(v!=p){
            sz[u] += dfs(v,u);
    }
    return sz[u] + 1;
}

int main() {
    optimize;
    int n; cin >> n;
    sz.resize(n + 2);
    for(int i = 2; i <= n;i++){
        int u; cin >> u;
        grafo[i].EB(u);
        grafo[u].EB(i);
    }
    dfs(1);
    for(int i = 1; i <=n;i++){
        cout << sz[i] << " ";
    }
    cout << endl;
    return 0;
}

