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


void acha_div(int  n, vi & div){
    for (int i = 2; i * i <= n; i++)
    {

        if (n % i == 0)
        {
            div.PB(i);
        }
    }
}
unordered_map<int,int> dp;
int calc(int n){
    if(dp.count(n)) return dp[n];
    vi div;
    acha_div(n,div);
    int ans = (n) / 2 + 1;
    for (auto x : div)
    {
        // dbg(x);
        int qtd = n / x;
        int qtd_pra_vencer = qtd / 2 + 1;
        int val_pra_vencer = calc(x);
        // dbg(qtd_pra_vencer);
        // dbg(val_pra_vencer);
        int op1 = qtd_pra_vencer * val_pra_vencer;
        // dbg(op1);
        ans = min(ans,op1);
        x = n/x;
        qtd = n/x;
        // dbg(qtd);
        qtd_pra_vencer = qtd / 2 + 1;
        val_pra_vencer = calc(x);
        // dbg(qtd_pra_vencer);
        // dbg(val_pra_vencer);
        int op2 = qtd_pra_vencer * val_pra_vencer;
        ans = min(ans,op2);
    }
    // dbg(ans);
    return  dp[n] = ans;
}


void solve()
{
    int n;
    cin >> n;
    cout << calc(n) << endl;
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
