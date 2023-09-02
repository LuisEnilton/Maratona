//
// Created by Luis on 31/08/2023.
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

int n;
int cost[21][21];
ll dp[1 << 21][21];
ll cnt = 0;
ll solve(bitset<21> mask,int i){
    if(mask.count() == n){
        return 1;
    }
    ll ans = 0;
    if(dp[mask.to_ulong()][i] !=-1){
        return dp[mask.to_ulong()][i];
    }
    for(int j =0;j < n;j++){
        if(!mask.test(j)){
            if(cost[i][j]){
                bitset<21> auxMask = mask;
                auxMask.set(j);
                ans += solve(auxMask,i+1);
            }
        }
    }
    return dp[mask.to_ulong()][i] = ans % MOD;
}

int main(int argc, char** argv)
{
    optimize;
    cin >> n;
    for(int i =0; i < n;i++){
        for(int j =0;j <n ;j++){
            cin >> cost[i][j];
        }
    }
    memset(dp,-1,sizeof dp);
    bitset<21> mask;
    cout << solve(mask,0) << endl;
    return 0;
}

