//
// Created by Luis on 15/01/2024.
//
//
// Created by Luis on 15/01/2024.
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
    int n,m; cin >> n >> m;
    vi nums(n);
    for(auto &x : nums) cin >> x;
    sort(ALL(nums));
    vi aux(m);
    for(auto &x : aux) cin >> x;
    sort(ALL(aux));
    int l1 = 0, r1 = n-1;
    int l2 = 0, r2 = m-1;
    ll ans = 0;
    for(int i = 0; i < n;i++){
        ll dif1 = abs(nums[l1] - aux[r2]);
        ll dif2 = abs(nums[r1] - aux[l2]);
        if(dif1 > dif2){
            l1++;
            r2--;
            ans+= dif1;
        }else{
            r1--;
            l2++;
            ans+=dif2;
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

