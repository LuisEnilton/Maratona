//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cmath>
#define int long long
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

void solve(){
    int n,k ; cin >> n >> k;
    vi nums(n);
    for(auto & x : nums) cin >> x;
    int l = 0, r = n-1;
    bool side = true;
    int ans = 0;
    while(l <= r && k > 0){
        if(side){
            if(nums[l] > nums[r]){
                k-= (2 * nums[r]);
                nums[l] -= nums[r];
            }else{
                k-= (nums[l] + nums[l] - 1);
                nums[r] -=(nums[l] - 1);
                side = !side;
            }
        }else{
            if(nums[r] > nums[l]){
                k-= (2 * nums[l]);
                nums[r] -= nums[l];
            }else{
                k-= (nums[r] + nums[r] - 1);
                nums[l] -=(nums[r] - 1);
                side = !side;
            }
        }
        if(k >=0) ans++;
        cout << "Lado : " << side << " " << k << endl;   
    }
    cout << ans  << endl;
}

signed main() {
    optimize;
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

