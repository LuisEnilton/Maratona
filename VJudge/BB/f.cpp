//
// Created by Luis on 06/09/2023.
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
int n, c;
vi nums;

bool check(ll m) {
    int q = 1; // eu sempre coloco no primeiro
    auto curr = nums.begin();
    while (true) {
        auto it = lower_bound(ALL(nums), *curr + m);
        if (it == nums.end()) return false; // n consegui achar
        q++;
        if (q == c) return true;
        curr = it;
    }
    return false;
}

void solve() {
    cin >> n >> c;
    nums = vi(n);
    for (auto &x: nums) cin >> x;
    sort(ALL(nums));
    ll l = 1, r = 10e9 + 10;
    ll ans;
    while (l <= r) {
        auto m = (l + r) / 2;
        if (check(m)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
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

