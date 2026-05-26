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
#define int ll
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXN = 1e5 + 5;
int c[MAXN], ans[MAXN];
vi g[MAXN];

map<int, int> cnt[MAXN]; // cada vertice conta a frequencia da ps na subarvore

void dfs(int u, int p = 0, int sum = 0)
{
    int ini = sum;
    sum += (c[u] ? 1 : -1);
    for (int v : g[u])
    {
        if (v == p)
            continue;

        dfs(v, u, sum);

        if(cnt[u].size() < cnt[v].size()){
            cnt[u].swap(cnt[v]);
        }

        for(auto &[k,val] : cnt[v]){
            cnt[u][k] += val;
        }
    }

    ans[u] = cnt[u][ini];
    cnt[u][sum]++;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> c[i];
    int m = n - 1;

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1);
    while (q--)
    {
        int u; cin >> u;
        cout << ans[u] << endl;
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
