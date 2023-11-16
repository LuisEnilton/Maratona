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


vector<ordered_set > grafo;
//Cada vertice tem uma lista de quantos vertices tem na subarvore de cada filho
vector<vi> filhos;
vector<int> ordem;
vii sub; // vai de {l, r-1}
int idx = 0;
void dfs(int u) {
    ordem.push_back(u);
    sub[u].first = idx++;
    for(auto v : grafo[u]){
        dfs(v);
    }
    sub[u].second = idx;
}





int main() {
    optimize;
    int n, q;
    cin >> n >> q;
    sub.resize(n + 1);
    grafo.resize(n+1);
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        grafo[u].insert(i);
    }
    dfs(1);
    while (q--) {
        int u,k; cin >> u >> k;
        if(sub[u].second - sub[u].first < k){
            cout << -1 << endl;
            continue;
        }
        cout << ordem[sub[u].first + k - 1] << endl;
    }
    return 0;
}

