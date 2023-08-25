//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
//
// Created by Luis on 22/08/2023.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
#define MAXN 1010
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>
int ancestral[MAXN][MAXL], nivel[MAXN], n;
pii dp[MAXN][MAXL]; // cada vertice tem um (max,min) associado no caminho até o ancestral i
vii grafo[MAXN];

void dfs(int u, int p = -1) {
    ancestral[u][0] = p;
    if (p != -1)
        nivel[u] = nivel[p] + 1;

    for (auto [v, peso]: grafo[u])
        if (v != p) {
            dp[v][0] = {peso, peso}; // numa aresta unica
            dfs(v, u);
        }
}

pii join(pii a, pii b) {
    pii ans;
    ans.first = min(a.first, b.first);
    ans.second = max(a.second, b.second);
    return ans;
}

void precalc() {
    memset(ancestral, -1, sizeof ancestral);
    dfs(1);
    for (int i = 1; i < MAXL; i++) {
        for (int j = 1; j <= n; j++) {
            if (ancestral[j][i - 1] != -1) {
                ancestral[j][i] = ancestral[ancestral[j][i - 1]][i - 1];
                dp[i][j] = join(dp[i][j - 1], dp[ancestral[i][j - 1]][j - 1]);
            }
        }
    }
}

int LCA(int u, int v) {
    if (nivel[u] < nivel[v]) swap(u, v);
    for (int i = MAXL - 1; i >= 0; i--) {
        if (ancestral[u][i] == -1)
            continue;
        int novo_posicao = ancestral[u][i];

        if (nivel[novo_posicao] >= nivel[v]) {
            //bit i está ligado
            u = novo_posicao;
        }

    }


    if (u == v) return u;
    for (int i = MAXL - 1; i >= 0; i--) {


        if (ancestral[u][i] != ancestral[v][i]) {
            u = ancestral[u][i];
            v = ancestral[v][i];

        }

    }


    return ancestral[u][0];
}

pii solve(int u , int v){

}


int main(int argc, char **argv) {
    optimize;

    precalc();
    return 0;
}






