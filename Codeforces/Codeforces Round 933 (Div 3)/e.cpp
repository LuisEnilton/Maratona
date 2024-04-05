//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cmath>

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
#define MAXN 101
#define MAXM 200010
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

int grid[MAXN][MAXM];

void solve() {
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<int> custo(n);
    for (int i = 0; i < n; i++) {
        vector<int> dp(m, INF);
        dp[0] = 1;
        for (int j = 0; j < m; j++) {
            int ant = INF;
            int aux = j;
            bool pula = true;
            for (int u = 1; u <= d + 1; u++) {
                if (j + u == m) break;
                dp[j + u] = min(dp[j + u], dp[j] + grid[i][j + u] + 1);
                if(dp[j + u] < ant && pula ){
                    aux++;
                    ant = dp[j+u];
                }else{
                    pula = false;
                }
            }
            j = aux;
        }
        custo[i] = dp[m - 1];
    }
    int ans = INF;
    for (int i = 0; i < n - k + 1; i++) {
        int sum = 0;
        for (int j = i; j < i + k; j++) {
            sum += custo[j];
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
}


int main() {
    optimize;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/* 1
  1 9 1 1
  0 1 90 1 90 1 90 1 0
 *
 *
 *
 *
 * */