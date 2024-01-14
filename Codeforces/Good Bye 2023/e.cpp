//
// Created by Luis on 30/12/2023.
//
//
// Created by Luis on 30/12/2023.
//
//
// Created by Luis on 30/12/2023.
//
//
// Created by Luis on 30/12/2023.
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

vi act;

multiset<int> dif;
int q = 0;
bool ok = false;
priority_queue<int> ans;
void dfs(int u, vector<vi > &grafo, int p = -1) {
    int ini = q;
    if (!dif.count(act[u])) q++;
    dif.insert(act[u]);
    ans.push(q);
    for (auto v: grafo[u]) {
        if (v == p) continue;
        (dfs(v, grafo, u));
    }
    if (dif.count(act[u]) == 1) q--;
    dif.erase(dif.find(act[u]));

}



void solve() {
    int n;
    cin >> n;
    act.clear();
    act.resize(n + 2);
    while(!ans.empty()){
        ans.pop();
    }
    q = 0;
    dif.clear();
    vector<vi > grafo(n + 2);
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        grafo[u].EB(i);
        grafo[i].EB(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> act[i];
    }
    ans.push(1);
    ans.push(1);
    dfs(1,grafo);
    int val1 = ans.top();ans.pop();
    int val2 = ans.top();ans.pop();
    cout << 1LL * val1 * val2 << endl;
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

