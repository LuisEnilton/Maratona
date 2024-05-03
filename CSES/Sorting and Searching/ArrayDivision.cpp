// Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cmath>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
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

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>
vector<ll> ps;
int n, k;
vl nums;
bool check(ll m)
{
    ll sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > m)
            return false;
        if (sum + nums[i] > m)
        {
            cnt++;
            sum = nums[i];
        }
        else
        {
            sum += nums[i];
        }
        if (cnt > k)
            return false;
    }
    return true;
}

int main()
{
    optimize;
    cin >> n >> k;
    nums.resize(n);
    ll sum = 0;
    ps.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }
    ll l = 0, r = sum;
    ll ans;
    cout << sum << endl;
    while (l <= r)
    {
        auto m = (l + r) / 2;
        if (check(m))
        {
            ans = r;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
