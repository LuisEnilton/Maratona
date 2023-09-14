//
// Created by Luis on 14/09/2023.
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


unordered_map<ll,ll> pai;
unordered_map<ll,ll> filho;

int main(int argc, char** argv)
{
    optimize;
    int n; cin >> n;
    vector<ll> nums(n);
    for(auto &x: nums) cin >> x;
    for(int i = 0; i < n;i++){
        for(int j = 0 ; j < n; j++){
            if(i == j) continue;
            if(nums[i] * 2 == nums[j] ){
                pai[nums[j]] = nums[i];
                filho[nums[i]] = nums[j];
            }
            if(nums[i]/3 == nums[j] && nums[i]%3 == 0){
                pai[nums[j]] = nums[i];
                filho[nums[i]] = nums[j];
            }
        }
    }
    ll num;
    for(int i = 0 ; i < n;i++){
        if(pai[nums[i]] == 0){
            num = nums[i];
        }
    }

    while(true){
        cout << num << " ";
        num = filho[num];
        if(num == 0) break;
    }
    cout << endl;
    return 0;
}

