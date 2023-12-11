//
// Created by Luis on 11/11/2023.
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
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vi problems(n);
    for (auto &p: problems) cin >> p;
    ll ans = 0;
    for (int i = 1; i < (1 << n); i++) {
        int mini = INF, maxi = 0;
        int total = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                total+=problems[j];
                mini = min(mini, problems[j]);
                maxi = max(maxi, problems[j]);

            }
        }

        if (total >= l && total <= r && (maxi - mini) >= x) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
