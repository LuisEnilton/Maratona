//
// Created by Luis on 14/11/2023.
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

vector<vector<int>> grafo;
vector<int> pre, low;
int clk=0;

vector<pair<int, int>> pontes;

void tarjan(int u, int p = -1){
    pre[u] = low[u] = clk++;


    for(auto v : grafo[u]){
        if(v == p) continue;

        if(pre[v] == -1)
        {
            tarjan(v, u);

            low[u] = min(low[v], low[u]);

            if(low[v] >  pre[u]) pontes.emplace_back(u, v);

        }
        else
            low[u] = min(low[u], pre[v]);
    }


}

void solve(int &n){
    pontes.clear();
    pre.clear();
    pre.resize(n + 1);
    low.clear();
    low.resize(n + 1);
    clk = 0;
    fill(ALL(pre),-1);
    tarjan(1);
}

int main()
{
    optimize;
    int t; cin >> t;
    for(int i = 1; i <=t;i++){
        cout << "Caso #" << i << endl;
        int n,m; cin >> n >> m;
        grafo.clear();
        grafo.resize(n+1);

        while(m--){
            int u,v; cin >>u >> v;
            grafo[u].EB(v);
            grafo[v].EB(u);
        }
        solve(n);
        if(pontes.size()){
            cout << pontes.size() << endl;
            for(auto &p : pontes){
                if(p.first > p.second) swap(p.first,p.second);
            }
            sort(ALL(pontes));
            for(auto [u,v] : pontes){
                cout << u << " " << v << endl;
            }
        }else{
            cout << "Sin bloqueos" << endl;
        }
    }
    return 0;
}

