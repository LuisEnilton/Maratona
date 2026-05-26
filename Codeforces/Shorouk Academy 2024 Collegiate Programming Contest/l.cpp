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
   int n; cin >> n;
   vi a(n);
   set<int> dis;
   for(auto & x : a) cin >> x,dis.insert(x);

    a.clear();
    for(auto x : dis) a.PB(x);
    n = a.size();

    vi primos = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

    int sz = primos.size();
    int ans = INFLL;
    for(int mask = 0; mask < (1 << sz);mask ++){


        bool ok = 1;

        int tot = 1;

        for(int i = 0; i < sz;i++){
            if((1 << i) & mask){
                tot *= primos[i];
            }
        }
        
        for(auto x : a){
            if(gcd(x,tot) < 2) ok = 0;
        }
        if(!ok) continue;

        ans = min(ans,tot);
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
