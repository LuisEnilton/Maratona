//
// Created by Luis on 19/12/2023.
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
int n;
int dfs(int u, int p = -1){
    int ans = 1; // conta o proprio vertice
    for(auto v : grafo[u]){
        if(v == p) continue;
        ans += dfs(v,u);
    }
    return  ans;
}

int solve(){
    int maior = 0;
    for(auto v : grafo[1]){
        maior = max(maior, dfs(v,1));
    }
    return n - maior; // soma mais um pra pegar a operacao final
}

int main() {
    optimize;
     cin >> n;
    grafo.resize(n+3);
    for(int i = 0; i < n - 1;i++){
        int u,v; cin >> u >> v;
        grafo[u].EB(v);
        grafo[v].EB(u);
    }

    cout << solve() << endl;
    return 0;
}

