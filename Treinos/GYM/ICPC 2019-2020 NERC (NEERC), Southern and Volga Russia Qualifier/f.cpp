
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
    vi nums(n);
    int ans = 0;
    int ans2 = 0;
    for (auto &x: nums) cin >> x;
    vi par(2);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        auto val = nums[i];
        if (val < 0) {
            sum++;
            par[sum % 2]++;
            ans += par[sum % 2];
            ans2 += par[(sum + 1) % 2];
        } else {
            ans2++;
            ans2 += (sum % 2 == 0 ? par[sum % 2] : par[sum % 2] - 1);
            ans += ((sum + 1) % 2 != 0 ? par[(sum + 1) % 2] + 1 : 0);
        }
    }
    cout << ans << endl;
    cout << ans2 << endl;
    return 0;
}

/*
 6
 -1 2 -3 -4 -5 -6

1 1 1 1 1
1 1 1 1
 * */
