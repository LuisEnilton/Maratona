//
// Created by Luis on 06/09/2023.
//
// Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define BT bitset<500>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define MAXN 300010
#define int ll
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

vi g[MAXN];
int tin[MAXN],tout[MAXN];
int clk = 0;

void dfs(int u, int p = 0 ){
    tin[u] = clk++;
    for(auto v : g[u]){
        if(v == p) continue;
        dfs(v,u);
    }
    tout[u] = clk;
}


int calc(vii & a){

    sort(ALL(a),[&](pii & x,pii & y){
        if(x.second == y.second){
            return x.first < y.first;
        }
        return x.second < y.second;
    });
    int prev = 0;
    int ans = 0;
    for(auto [l,r] : a){
        if(l < prev) continue;
        prev = r;
        ans++;
    }


    return ans;
}


void solve()
{
   int n,q; cin >> n >> q;

    for(int i = 2; i <=n;i++){
        int p; cin >> p;
        g[p].emplace_back(i);
        g[i].emplace_back(p);
    }
    dfs(1);

    while(q--){
        int m; cin >> m;

        vii intervals;

        while(m--){
            int u; cin >> u;
            intervals.emplace_back(tin[u],tout[u]);
        }
        cout << calc(intervals) << endl;
    }

}

signed main()
{
    optimize;
    int t = 1;
    //   cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
