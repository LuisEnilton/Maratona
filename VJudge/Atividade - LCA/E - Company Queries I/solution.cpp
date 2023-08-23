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
#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>
int dp[MAXN][MAXL], nivel[MAXN], n;
vi grafo[MAXN];

void dfs(int u, int p = -1) {
    dp[u][0] = p;
    if (p != -1)
        nivel[u] = nivel[p] + 1;

    for (auto &v: grafo[u])
        if (v != p)
            dfs(v, u);
}


void precalc() {
    memset(dp, -1, sizeof dp);
    dfs(1);
    for (int i = 1; i < MAXL; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[j][i - 1] != -1) {
                dp[j][i] = dp[dp[j][i - 1]][i - 1];
            }
        }
    }
}



int fastExp(int base, int exp){
    int ret = 1;

    while(exp){
        if((exp&(1))) ret = (ret * base)%MOD;
        base = (base * base)%MOD;
        exp >>= 1;
    }

    return ret;
}

int main(int argc, char** argv)
{
    optimize;
    int q;
    cin >> n >> q;
    for(int i = 2 ; i <= n;i++){
        int node; cin >> node;
        grafo[i].PB(node);
        grafo[node].PB(i);
    }
    precalc();
    while(q--){
    int mask = 1;
    int node; cin >> node;
    int lvl; cin >> lvl;
    int numBits = log2(lvl) + 1;
    int curr = node;
    for (int i = 0; i < numBits; ++i) {
        int bit = (lvl & mask) >> i;
        if(bit == 1 && curr != -1){
            curr = dp[curr][i];
        }
        //cout << bit << endl;
        mask <<= 1;
    }
    cout << curr << endl;
    }
    return 0;
}

