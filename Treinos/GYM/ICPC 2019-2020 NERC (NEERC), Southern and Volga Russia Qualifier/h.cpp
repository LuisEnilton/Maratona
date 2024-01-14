//
// Created by Luis on 14/01/2024.
//
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
#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>


int main() {
    optimize;
    int n;
    cin >> n;
    vi l(n);
    vector<int> d;
    for (auto &x: l) cin >> x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            d.push_back(l[i] - l[j]);
        }
    }
    UNIQUE(d);
    sort(ALL(d));
    map<pair<ll, int>, int> dp;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {

        for (int j = 0; j < d.size(); j++) {
            if(i == n - 1){
                dp[{l[i],j}] = 1;
            }

            if (l[i] + d[j] > l[n - 1]) break;
            dp[{l[i], j}] = max(dp[{l[i], j}], dp[{l[i] + d[j], j}] + 1);
            ans = max(ans, dp[{l[i], j}]);
        }
    }
    cout << ans << endl;
    return 0;
}

