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
#define ALL(x) x.begrafoin(), x.end()
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


//1 - Indexado
pair<int, vector<int>> center(vector<vi > &grafo) {
    int f, df;
    int n = grafo.size();
    vi d(n + 1), par(n + 1);
    function<void(int)> dfs = [&](int v) {
        if (d[v] > df) f = v, df = d[v];
        for (int u: grafo[v])
            if (u != par[v])
                d[u] = d[v] + 1, par[u] = v, dfs(u);
    };

    f = df = par[1] = -1, d[1] = 0;
    dfs(1);
    int root = f; // o mais longe que chegou na 1ª dfs
    f = df = par[root] = -1, d[root] = 0;
    dfs(root);

    vector<int> c;
    while (f != -1) {
        if (d[f] == df / 2 or d[f] == (df + 1) / 2) c.push_back(f);
        f = par[f];
    }
    if(c.size() == 2){
        if(abs(d[1] - d[c[0]]) < abs(d[1] - d[c[1]])){
            swap(c[0],c[1]);
        }
    }
    return {df, c};
}


int main() {
    optimize;
    int n, m;
    cin >> n >> m;
    vector<vi > grafoCirc(n + 1),grafoQuad(m+1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        grafoCirc[u].EB(v);
        grafoCirc[v].EB(u);
    }

    for(int i = 0; i < m-1;i++){
        int u, v;
        cin >> u >> v;
        grafoQuad[u].EB(v);
        grafoQuad[v].EB(u);
    }
    auto ans = center(grafoCirc);
    auto ans2 = center(grafoQuad);
    cout << ans.second[0] << " " << ans2.second[0] << endl;
    return 0;
}

