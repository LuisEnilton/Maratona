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
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define int ll
#define dbg(x) cout << #x << " " << x << endl;
// #define endl '\n'
#define print_arr(a)      \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl;
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>
const int MAXN = 2 * 1e5 + 5;
set<int> adj[MAXN];
set<int> rev[MAXN];
void solve()
{
    int n,m; cin >> n >> m;

    while(m--){
        int u,v;cin >> u >> v;
        adj[u].insert(v);
        rev[v].insert(u);
    }
    pii ans = {1,0}; // id,val
    for(int i = 1;i <=n;i++){
        // dbg(i);
        int cnt = 0;
        for(auto v : rev[i]){
            if(!adj[i].count(v)) cnt++;
        }
        if(cnt > ans.second){
            ans = {i,cnt};
        }
    }
    cout << ans.first << " " << ans.second << endl;
}

signed main()
{
    optimize;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
