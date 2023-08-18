//
// Created by Luis on 17/08/2023.
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
#define MAXN 101010
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>


int n, nums[MAXN],pai[MAXN], nivel[MAXN];



vi grafo[MAXN];
vi posicoes[MAXN];
void dfs(int u, int p = -1){
    pai[u] = p;
    if(p!=-1)
        nivel[u] = nivel[p] + 1;

    for(auto &v : grafo[u])
        if(v != p)
            dfs(v, u);
}

void precal(){
    dfs(1);
}

int LCA(int u, int v){
    if(nivel[u] < nivel[v]) swap(u,v);

    // anda com u até chegar no nivel de v
    while(pai[u] != pai[v]){
        u = pai[u];
    }

    if(u == v) return u;
    //anda com os dois ao mesmo tempo até chegar no mesmo pai
    while(pai[u] != pai[v]){
        u = pai[u];
        v = pai[v];
    }

    return pai[u];
}

//

int dist(int u ,int v){
    int lca = LCA(u,v);

    return nivel[u] + nivel[v] - 2 * nivel[lca];
}

int main(int argc, char** argv)
{
    optimize;

    cin >> n;

    for(int i =1 ;i <=n;i++) {
        cin >> nums[i];
        posicoes[nums[i]].PB(i);
    }


        for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;

        grafo[u].PB(v);
        grafo[v].PB(u);
    }
        ll ans = 0;
        for(int i = 1; i <=n; i++){
            int u = posicoes[i][0];
            int v = posicoes[i][1];

            ans += dist(u,v);
        }
        cout << ans << endl;
        return 0;
}

