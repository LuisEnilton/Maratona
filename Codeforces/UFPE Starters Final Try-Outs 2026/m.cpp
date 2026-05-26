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


void solve()
{
    int n,m; cin >> n >> m;

    vi cnt(m),a (n);
    
    for(auto & x : a) cin >> x,cnt[x]++;

    cnt.insert(cnt.end(),ALL(cnt));

    vi ps(cnt.size() + 1), ps2(cnt.size() + 1);

    for(int i = 1; i <= cnt.size();i++){
        ps[i] = ps[i - 1] + cnt[i - 1];
        ps2[i] = ps2[i - 1] + (cnt[i - 1] * (i - 1));
        // cout << ps[i] << " " << ps2[i] << endl;
    }
    // testando cada pos como centro
    int ans = INFLL;
    for(int pos = (m)/2;pos < (m)/2 + m;pos++){
        int sum = 0;
        // dbg(pos);
        if(m & 1){
            int d = m/2;
            int prev = (ps[pos] - ps[pos - d]) * pos;
            prev -=(ps2[pos] - ps2[pos - d]);
            // dbg(prev);
            sum += prev;
            int aft =  (ps2[pos + d + 1] - ps2[pos]);
            aft -=(ps[pos + d +  1] - ps[pos]) * pos;
            // dbg(aft);
            sum += aft;
        }else{
            int d = (m/2) - 1;
            int prev = (ps[pos] - ps[pos - d]) * pos;
            prev -= (ps2[pos] - ps2[pos - d]);
            // dbg(prev);
            sum += prev;
            int aft = (ps2[pos + d + 2] - ps2[pos]);
            aft -= (ps[pos + d + 2] - ps[pos]) * pos;
            // dbg(aft);
            sum += aft;
        }
        // cout << pos << " " << sum << endl;
        ans = min(ans,sum);
    }
    cout << ans << endl;
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
