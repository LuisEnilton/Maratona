//
// Created by Luis on 21/09/2023.
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

vector<ll> nums;

ll amount(ll height){
    ll ret = 0;
    for(auto x : nums){
        ret += max(height - x,0LL);
    }
    return ret;
}

int main(int argc, char** argv)
{
    optimize;
    int t; cin >> t ;
    while(t--){
        int n;
        ll x;
        cin >> n >> x;
        nums = vector<ll>(n);
        ll maior = 0;
        for(auto &num : nums) {
            cin >> num;
            maior = max(maior,num);

        }
        ll l = 0, r = x + maior + 1;
        ll ans;
        while(l <=r){
            int mid = (l+r) / 2;

            if(amount(mid) <= x){
                ans = mid;
                l = mid+1;
            }else{
                r = mid -1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

