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
#define int ll
#define vi vector<int>
#define vb vector<bool>
#define BT bitset<500>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define MAXN 1010101
#define endl '\n'
#define dbg(x) cout << #x << " " << x << endl;
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

vector<bool> primo(MAXN,1);

void solve()
{
    
    int n; cin >> n;

    vi a(n);

    for(auto & x : a) cin >> x;

    sort(ALL(a));

    int sl = a[0], sr = a[n - 1];
    int cntl = 1, cntr = 1;

    int ans = a[n - 1] - a[0];
    int l = 1, r= n - 2;
    cout << ans << " ";
    // dbg(ans);
    while(l <= r){

        int op1 = (cntl * a[l] - sl) + (sr - cntr * a[l]); 
        int op2 = (cntl * a[r] - sl) + (sr - cntr * a[r]); 
        // dbg(op1);
        // dbg(op2);
        if(op1 >= op2){
            sl += a[l];
            ans += op1;
            cntl++;
            l++;
        }else{
            sr += a[r];
            ans += op2;
            cntr++;
            r--;
        }
        // dbg(ans);
        cout << ans << " ";
    }
    cout << endl;


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