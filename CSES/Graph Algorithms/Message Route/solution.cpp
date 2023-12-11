//
// Created by Luis on 18/11/2023.
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
const int maxn = 10e5 + 5;
vector<int> grafo[maxn];
vector<int> pai;
int n;

vi bfs(int o) {
    queue<int> fila;
    vector<bool> visited(n + 1,false);
    vector<int> dist(n+1,INF);
    dist[o] = 0;
    fila.push(o);
    while (!fila.empty()) {
        auto atual = fila.front();
        fila.pop();
        if(visited[atual]) continue;
        visited[atual] = true;
        for (auto v: grafo[atual]) {
            if(dist[v] > dist[atual] + 1){
                dist[v] = dist[atual] + 1;
                fila.push(v);
                pai[v] = atual;
            }
        }
    }
    return dist;
}

int main() {
    optimize;
    int m;
    cin >> n >> m;
    pai.resize(n + 1);
    fill(ALL(pai), -1);
    while(m--){
        int u,v; cin >> u >> v;
        grafo[u].EB(v);
        grafo[v].EB(u);
    }

    bfs(1);
    auto dist = bfs(1);
    if(dist[n] == INF){
        cout << "IMPOSSIBLE" << endl;
    }else{
        vi ans;
        for(int v = n; v!=-1;v = pai[v]){
            ans.push_back(v);
        }
        reverse(ALL(ans));
        cout << ans.size() << endl;
        for(auto x : ans){
            cout << x <<" ";
        }
        cout << endl;
    }
    return 0;
}

