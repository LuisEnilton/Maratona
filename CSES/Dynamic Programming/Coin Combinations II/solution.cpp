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
int n, x;
vi coins;
const int maxn = 10e6 + 2;
map<pii, ll> dp;

ll solve(int q, int i) {

    if (q == x) {
        return 1;
    }

    if (q > x || i >= n) return 0;

    if (dp.count({q, i}) == 1) return dp[{q, i}];

    ll ans = 0;

    ll continua = solve(q + coins[i], i);

    ll troca = solve(q, i + 1);

    ans = (continua + troca) % MOD;

    return dp[{q, i}] = ans;

}


int main(int argc, char **argv) {
    optimize;
    cin >> n >> x;
    coins.resize(n);
    for (auto &c: coins) cin >> c;
    cout << solve(0, 0) << endl;
    return 0;
}

