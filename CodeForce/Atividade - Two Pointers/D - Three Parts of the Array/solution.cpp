//
// Created by Luis on 08/07/2023.
//
//
// Created by Luis on 07/07/2023.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 10000000
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
#define MAXN 200110
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

int N;
vector<ll> nums;


int main(int argc, char **argv) {
    optimize;
    cin >> N;
    nums.resize(N);
    for (auto &x: nums) cin >> x;
    int i = 0, j = N - 1;
    ll sum1 = 0, sum3 = 0,ans = 0;
    while (i <= j) {
        if(sum1 <= sum3){
            sum1 += nums[i];
            i++;
        }else{
            sum3 += nums[j];
            j--;
        }
        if(sum1 == sum3 && sum1>ans)
            ans = sum1;
    }
    cout << ans << endl;

    return 0;
}