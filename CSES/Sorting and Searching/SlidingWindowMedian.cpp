//
// Created by Luis on 06/09/2023.
//
// Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
#define int ll
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less_equal<os_type>, rb_tree_tag, tree_order_statistics_node_update>


signed main() {
    optimize;
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (auto &x: a) cin >> x;
    ordered_set nums;

    for (int i = 0; i < k; i++) {
        nums.insert(a[i]);
    }
    int ans = *nums.find_by_order((k-1) / 2);
    cout << ans << " ";

    for (int i = k ; i < n; i++) {
        int leaving = a[i - k];
        nums.erase(nums.upper_bound(leaving));
        int enter = a[i];
        nums.insert(enter);
        /*cout << i << " : ";
        for(auto x : nums) {
            cout << x << " ";
        }
        cout << endl;*/
        int ans = *nums.find_by_order((k-1) / 2);
        cout << ans << " ";
    }
    cout << endl;
}

// 1 2 3 4 5
// 2 5 1 4 3 - 11
// 3 5 2 4 1 -

// 1 2 3 2 3 4 3 1 4
