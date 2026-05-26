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
#define int ll
#define dbg(x) cout << #x << " " << x << endl;
// #define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>



const int MAXN =1e7 + 5;
int lp[MAXN]; // menor primo
bool no_primo[MAXN];

void solve()
{
   
    int n; cin >> n;
    vi a(n), b(n);
    for(auto & x : a) cin >> x;
    for(auto & x : b) cin >> x;
    int ans = 0;
    for(int i = 0 ;i < n;i++){
        // dbg(i);
        while(a[i] > 1 || b[i] > 1){
            // dbg(a[i]);
            // dbg(b[i]);
            if(a[i ] == b[i]){
                break;
            }else if(a[i] > b[i]){
                a[i] = a[i] / lp[a[i]];
                ans++;
            }else{
                b[i] = b[i] / lp[b[i]];
                ans++;
            }
        }
    }
    cout << ans << endl;

}

signed main()
{
    optimize;

    for(int i = 2; i < MAXN;i++){

        if(no_primo[i]) continue;
        lp[i] = i;
        for(int j = i * i;j < MAXN;j += i){
            if(lp[j] == 0) lp[j] = i;
            no_primo[j] = 1;
        }
    }

    int t = 1;
      cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
