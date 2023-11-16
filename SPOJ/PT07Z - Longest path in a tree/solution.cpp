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
const int maxn = 10010;
vi grafo[maxn];

int dfs(int u,int pai){
    int ret = 0;
    for(auto v : grafo[u]){
        if(v == pai) continue;
        ret = max(ret,1 + dfs(v,u));
    }
    return ret;
}


int solve(){
    int o = 1;
    vi vals;
    vals.push_back(0);
    vals.push_back(0);
    for(auto v : grafo[o]){
        int val = 1 + dfs(v,o);
        vals.push_back(val);
    }
    sort(ALL(vals));
    return vals[vals.size() - 1] + vals[vals.size()-2];
}



int main()
{
    optimize;
    int n;
    cin >> n;
    for(int i = 0 ; i < n-1;i++){
        int u,v; cin >>u >> v;
        grafo[u].EB(v);
        grafo[v].EB(u);
    }
    cout << solve() << endl;

    return 0;
}

