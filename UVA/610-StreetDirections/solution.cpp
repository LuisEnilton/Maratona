//
// Created by luise on 16/11/2023.
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

vector<vi> grafo;

vi pre,low;
int clk = 0;
map<pii,bool> dir;
void tarjan(int u, int p = -1){
    pre[u] = low[u] = clk++;

    for(auto v : grafo[u]){
        if(v == p) continue;
        pii a = {u,v};
        if(pre[v] == -1)
        {
            tarjan(v, u);

            low[u] = min(low[v], low[u]);

            if(low[v] >  pre[u]){
                dir[a] = true;
            }else{
                dir[a] = false;
            }

        }
        else{
            low[u] = min(low[u], pre[v]);
            if(!dir.count({a.second,a.first}))
                dir[a] = false;

        }
    }

}

void clear(){
    grafo.clear();
    dir.clear();
    pre.clear();
    low.clear();
}

int main()
{
    optimize;
    int n,m;
    int t = 1;
    while(cin >> n >> m && (n!=0 || m!=0)){
        clear();
        grafo.resize(n+1);
        pre.resize(n+1);
        low.resize(n+1);
        fill(ALL(pre),-1);
        while(m--){
            int u,v; cin >> u >> v;
            grafo[u].EB(v);
            grafo[v].EB(u);
        }
        tarjan(1);
        cout << t << endl;
        cout << endl;
        for(auto x : dir){
            auto [u,v] = x.first;
            bool ok = x.second;
            if(ok){
                cout << u << " " << v << endl;
                cout << v << " " << u << endl;
            }else{
                cout << u << " " << v << endl;
            }
        }
        cout << "#" << endl;
        t++;
    }
    return 0;
}

