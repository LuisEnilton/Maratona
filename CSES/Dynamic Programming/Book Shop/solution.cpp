//
// Created by Luis on 26/10/2023.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101
#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

int n,x;
vi prices;
vi pages;
int dp[1001][100010];
int solve(int i,int q){
    if(q > x){
        return -INF;
    }
    if(i == n) return 0;
    if(~dp[i][q]) return dp[i][q];
    ll pega = pages[i] + solve(i+1,q+prices[i]);
    ll n_pega = solve(i+1,q);

    return dp[i][q] =  max(pega,n_pega);
}

int main()
{
    optimize;
    cin >> n >> x;
    prices.resize(n);
    pages.resize(n);
    for(auto &p : prices) cin >> p;
    for(auto &pg:pages) cin >> pg;
    memset(dp,-1,sizeof dp);
    cout << solve(0,0) << endl;
    return 0;
}

