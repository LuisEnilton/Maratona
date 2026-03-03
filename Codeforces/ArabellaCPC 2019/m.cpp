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
   string s; cin >> s;
   vi cnt(26);

   for(auto c : s){
    cnt[c - 'a']++;
   }
   string ans = "";
   for(int i = 0;i< 26;i++){

        if(i == 25){

            for(int j = 0; j < cnt[i];j++){
                ans += ('a' + i);
            }

            break;
        }

        int q = cnt[i]/2;

        cnt[i] -= (2 * q);
        cnt[i + 1] += q;

        if(cnt[i] & 1) ans += ('a' + i);
   }
   sort(ALL(ans));
   reverse(ALL(ans));

   cout << ans << endl;
}

signed main()
{
    optimize;
    int t = 1;
    //  cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
