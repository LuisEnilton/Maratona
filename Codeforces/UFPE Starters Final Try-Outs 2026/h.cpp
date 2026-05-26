//
// Created by Luis on 06/09/2023.
//
// Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);
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
#define MAXN 2010
#define int ll
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>
int dp[MAXN][MAXN];

int n;
vii pts;
int calc(int t, int idx)
{
    if(t == n) return 0;
    // cout << t << " " << idx << endl;
    auto & at = dp[t][idx];
    if(~at) return at;
    int d = (pts[t].second - pts[idx].second); 
    // dbg(d);
    int nd = abs(pts[t].first - pts[idx].first);
    // dbg(nd);
    int n_pega = calc(t + 1,idx);
    int pega = 0;
    if(nd <= d) pega = 1 + calc(t + 1,t);

    return at = max(pega,n_pega);

}

void solve()
{
    memset(dp, -1, sizeof dp);
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        pts.EB(x, y);
    }
    
    sort(ALL(pts),[&](pii & a, pii & b){
        return a.second < b.second;
    });

    pts.EB(0,0);

    cout << calc(0,n) << endl;

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
