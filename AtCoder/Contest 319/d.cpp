//
// Created by Luis on 09/09/2023.
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

int n,m;
vector<ll> nums;

bool check(ll val){
    ll cont = 1;
    ll sum = 0;
    int cur = 0;
    while(cur < n){
        if(nums[cur] > val) return false;
        if(sum + nums[cur] > val){
            sum = 0;
            cont++;
        }

        if(cont > m) {
            return false;
        }

        sum+=nums[cur];
        cur++;
        if(cur >=n) break;

        if(sum + 1 > val){
            sum = 0;
            cont++;
        }else{
            sum+=1;
        }

        if(cont > m) return false;
    }
    return true;
}


int main(int argc, char** argv)
{
    optimize;
    cin >> n >> m;
    nums.resize(n);
    ll sum = 0;
    for(auto &x: nums){
        cin >> x;
        sum+=x;
    }
    ll l = 0, r = sum + n;
    ll ans = 1;
    while(l<=r){
        ll mid = (l+r)/2;
        if(check(mid)){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout << ans << endl;
    return 0;
}

