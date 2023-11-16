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
#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

vector<int> pares,impares;

void bfs(vector<bool> &chosen,vector<vi> &grafo,vector<bool> &visited){
    queue<pii> fila;
    fila.push({1,0});
    while(!fila.empty()){
        auto [u,pai] = fila.front();
        fila.pop();
        if(visited[u]) continue;
        visited[u] = true;
        if(!chosen[u]){
            pares.push_back(u);
        }else{
            impares.push_back(u);
        }
        for(auto v : grafo[u]){
            if(v == pai || visited[v]) continue;
            chosen[v] = !chosen[u];
            fila.push({v,u});
        }
    }
}


void solve() {
    int n, m;
    cin >> n >> m;
    pares.clear();
    impares.clear();
    vector<vi> grafo(n+1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        grafo[u].EB(v);
        grafo[v].EB(u);
    }
    vector<bool> chosen(n+1);
    vector<bool> visited(n+1);
    bfs(chosen,grafo,visited);
    if(pares.size() > impares.size()){
        cout << impares.size() << endl;
        for(auto x : impares){
            cout << x << " ";
        }
    }else{
        cout << pares.size() << endl;
        for(auto x : pares){
            cout << x << " ";
        }
    }
    cout << endl;
}


int main() {
    optimize;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

