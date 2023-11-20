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
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>


void solve() {
    int n;
    cin >> n;
    vi s(n);
    vi nums(n);
    int ans;
    cin >> nums[0];
    s[0] = nums[0];
    ans = nums[0];
    for (int i = 1; i < n; i++) {
        cin >> nums[i];
        int op1 = nums[i], op2 = -INF;
        if (abs(nums[i] % 2) != abs(nums[i - 1] % 2)){
            op2 = s[i-1] + nums[i];
        }
        s[i] = max(op1,op2);
        ans = max(ans,s[i]);
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

