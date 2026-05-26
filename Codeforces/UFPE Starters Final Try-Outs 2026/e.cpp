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
#define MAXN 500010
#define int ll
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>



void solve()
{
   
    int n = 8;
    string ans;
    while(n--){
        string s; cin >> s;
        int cnt = 0;
        for(auto c : s){
            
            if(c != '.'){
                if(cnt) ans += char('0' + cnt);
                cnt = 0;
                ans += c;
            }else{
                cnt++;
            }

        }
        if(cnt) ans += char('0' + cnt);
        ans += '/';
    }
    ans.pop_back();
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
