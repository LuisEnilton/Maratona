//
// Created by Luis on 27/06/2023.
//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <string>
#include <algorithm>
#include <set>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 100000010
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
#define MAXN 1010010
#define MAXL 23
#define endl '\n'
#define int long long
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;

int n, c, t;
vi nums;

//
bool check(int time) {
    int cnt = 0;
    int q = t * time;
    int aux = q;
    for (int i = 0; i < n; i++) {
        if (cnt > c) return false;
        if (nums[i] > q) return false;

        if (nums[i] > aux) {
            cnt++;
            aux = q;
            i--;
            continue;
        }
        if (cnt == c) return false;
        aux -= nums[i];
    }
    return true;
}


signed main() {
    optimize;
    cin >> n >> c >> t;
    nums.resize(n);
    for (auto &x: nums) cin >> x;
    int l = 0, r = 10e11;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
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



