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
const int maxn = 1001;
char grid[maxn][maxn];
ll dp[maxn][maxn];
int n;

ll solve(int y, int x) {
    if (y == n || x == n) return 0;
    if (grid[y][x] == '*') return 0;
    if (y == n - 1 && x == n - 1) return 1;


    if (~dp[y][x]) return dp[y][x];
    ll dir = solve(y, x + 1);
    ll baixo = solve(y + 1, x);

    return dp[y][x] = (dir + baixo) % MOD;
}


int main() {
    optimize;

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0) << endl;
    return 0;
}

