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
#define MAXN 1010101
#define int ll
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

void solve()
{
    int n,m,k; cin >> n >>  m >> k;
    vi a(n);
    for(auto & x : a) cin >> x;
    auto calc = [&](int x){
        if(x % m == 0) return x/m;
        if(m > x) return 0ll;
        int l = 0, r = x/m;

        int ans = 0;
        while(l <= r){

            int q= (l + r)/2; // tento uma quantidade q , a[i] - q * m >= k

            int val = x - (q * m);

            if(val >= k){
                ans = q;
                l = q + 1;
            }else{
                r = q - 1;
            }
        }
        return ans;
    };
    int ans = 0;
    for(auto x : a){
        ans += calc(x);
    }

    cout << ans << endl;

}

signed main()
{
    optimize;
    int t = 1;
      cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
