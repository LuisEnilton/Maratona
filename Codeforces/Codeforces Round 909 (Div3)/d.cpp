//
// Created by Luis on 17/11/2023.
//
//
// Created by Luis on 17/11/2023.
//
//
// Created by Luis on 17/11/2023.
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
#define EPS 1e-6
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

//log a + b == logb + a = > loga - a == logb - b = > a - loga == b - logb
// ((1+ n - 1) * (n-1)) /2




void solve() {
    int n;
    cin >> n;
    vector<double> nums(n);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        nums[i] = (double) val - log2(val);
    }
    sort(ALL(nums));
    ll ans = 0;
    for (ll i = 0; i < n;) {
        double val = nums[i];
        ll qtd = upper_bound(ALL(nums), val) - lower_bound(ALL(nums), val);
        ans += ((1 + qtd - 1) * (qtd - 1)) / 2;
        i += qtd;
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
