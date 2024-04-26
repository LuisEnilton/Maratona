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

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

struct machine {
    ll k;
    int id;
    ll t;

    machine(ll k, int id, ll t) : k(k), id(id), t(t) {}

    bool operator<(machine m) const {
        if (t == m.t)
            return k > m.k;
        return t > m.t;
    }
};

vector<ll> nums;
ll n, x;

bool check(ll t) {
    ll tot = 0;
    for (auto num: nums) {
        tot += (t / num);
        if(tot >=x) return true;
    }
    return false;
}

int main() {
    optimize;
    cin >> n >> x;
    nums.resize(n);
    for (auto &k: nums) cin >> k;
    ll l = 0, r = INFLL;
    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}

