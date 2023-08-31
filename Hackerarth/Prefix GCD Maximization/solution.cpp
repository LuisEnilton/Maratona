//
// Created by Luis on 31/08/2023.
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

int n;
vector<ll> nums;
ll memo[2 << 20][21];

vector<ll> compress(vector<ll> &v) {
    vector<ll> ret = v;
    for (auto &x: ret) {
        x = POS(v, x);
    }
    return ret;
}

ll solve(bitset<20> mask, int i, vector<ll> &pos) {
    if (i == n) {
        return 0;
    }
    mask.set(pos[i]);

    if(memo[mask.to_ulong()][i] != -1){
        return memo[mask.to_ulong()][i];
    }

    ll result = 0;
    for (int j = i; j >= 0; j--) {
        result = gcd(result, nums[pos[j]]);
    }
    ll val;
    val = solve(mask, i + 1, pos);
    return memo[mask.to_ulong()][i] = val + result;


}

int main(int argc, char **argv) {
    optimize;
    cin >> n;
    nums.resize(n);
    for (auto &x: nums) cin >> x;
    sort(ALL(nums));
    vector<ll> pos = compress(nums);
    memset(memo, -1, sizeof memo);
    ll ans = 0;
    do {
        bitset<20> mask;
        ans = max(ans, solve(mask, 0, pos));

    } while (next_permutation(ALL(pos)));
    cout << ans << endl;
    return 0;
}

