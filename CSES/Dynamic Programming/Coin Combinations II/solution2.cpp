//
// Created by Luis on 27/10/2023.
//
//
// Created by Luis on 28/09/2023.
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



// dp[x][n] = dp[x - cn][n] + dp[x][n-1]
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    // dp[i][k] = number of ways to construct sum k
    // such that all coins before coin[i] are unusable

    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    }

    for(int i = n - 1; i >= 0; i--){
        for(int sum = 1; sum <= x; sum++){
            int skipping = dp[i + 1][sum];
            int picking = 0;
            if(a[i] <= sum){
                picking = dp[i][sum - a[i]];
            }
            dp[i][sum] = (skipping + picking) % MOD;
        }
    }
    cout << dp[0][x] << endl;
    return 0;
}

