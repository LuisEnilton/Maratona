#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
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
#define MAXN 5050
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

ll dp[MAXN][MAXN], L, T;

int professores[MAXN][3];

ll solve(int i, int k)
{
    if (i == T) return (k == L ? 0 : INFLL);
    if (k > L) return INFLL;
    if (dp[i][k] != -1) return dp[i][k];

    return dp[i][k] = min({solve(i + 1, k), solve(i + 1, k + 1) + professores[i][0], solve(i + 1, k + 2) + professores[i][1], solve(i + 1, k + 3) + professores[i][2]});
}


int main(int argc, char** argv)
{
    optimize;

    memset(dp, -1, sizeof(dp));

    cin >> L >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> professores[i][0] >> professores[i][1] >> professores[i][2];
    }

    cout << solve(0, 0) << endl;

    return 0;
}