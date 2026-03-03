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
#define MAXN 101010
#define int ll
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

int dp[MAXN][2];
int n;
string s;
vi a;
int calc(int i , bool t){
    if(i == n) return t;
    if(~dp[i][t]) return dp[i][t];
    int op1 = (a[i] + t) + calc(i + 1,0);

    int op2 = ((9 - a[i]) + (!t)) + calc(i + 1,1);
    // dbg(i);
    // dbg(t);
    // dbg(op1);
    // dbg(op2);
    return dp[i][t] = min(op1,op2);

}



void solve()
{
    memset(dp,-1,sizeof dp);
    cin >> s;
    n = s.size();
    for(int i = n - 1;i >=0;i--){

        int x = s[i] - '0';
        a.PB(x);
    }
    // dp[i][t]
    // na posicao i dado que o anterior comecou do final ou n , t = sim

    int ans = calc(0,0);

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
