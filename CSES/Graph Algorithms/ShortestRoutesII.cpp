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
#define MAXN 502
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

int n;
int d[MAXN][MAXN];

bool floyd_warshall(){
    for(int k = 0; k < n;k++)
        for(int i = 0; i < n;i++)
            for(int j = 0; j < n;j++)
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);

    for(int i = 0; i < n;i++){
        if(d[i][i] < 0) return 1;
    }
    return 0;
}


int main() {
    optimize;
    for(int i = 1; i <=n;i++){
        d[i][i] = 0;
    }
    int n,m,q; cin >> n >> m >> q;
    while(m--){
        int u,v,c; cin >> u >> v >> c;
        d[u][v] = c;
        d[v][u] = c;
    }
    floyd_warshall();
    while(q--){
        int u,v; cin >> u >> v;
        cout << (d[u][v] == INF?-1:d[u][v]) << endl;
    }
    return 0;
}

