//
// Created by luise on 12/12/2023.
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
    int n, m;
    cin >> n >> m;
    vi nums(n);
    for (auto &x: nums) cin >> x;
    //Balancear avançando pelas duas pontas
    int l = 0, r = n - 1;
    if(n == 1){
        cout << abs(m - nums[0]) << endl;
        return 0;
    }
    int ans = 0;
    while (l < r) {
        int val = m - nums[l];
        nums[l] += val;
        nums[l + 1] += val;
        ans += abs(val);
        val = m - nums[r];
        nums[r] += val;
        nums[r - 1] += val;
        ans += abs(val);
        l++, r--;
    }
    cout << ans << endl;
    return 0;
}

