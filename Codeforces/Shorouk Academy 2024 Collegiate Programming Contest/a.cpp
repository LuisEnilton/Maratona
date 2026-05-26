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

    int curr = 1;
    int nxt = 1;
    int cnt = 1, ans = 0;
    
    auto q_10 = [&](int x){
        int resp = 0;
        while(x > 0){
            resp++;
            x/=10;
        }
        return resp;
    };

    int qn = q_10(n);
    while(curr <= n){
        if(cnt == qn){
            if(cnt & 1)
                ans += (n - curr + 1);
            break;
        }
        
        nxt *= 10; 
        // dbg(nxt);
        int q = (nxt - curr);

        if(cnt & 1) ans += q;

        cnt++;
        curr = nxt;
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
