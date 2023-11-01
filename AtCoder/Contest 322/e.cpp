//
// Created by luise on 31/10/2023.
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

map<pair<int,ll>,ll> dp;

int n,k,p;
bool check(vi &nums){
    for(auto x : nums)
        if(x < p) return false;
    return true;
}

ll solve(int i,vi nums,vector<vi> &parametros,int c,vi &custos){
    if(check(nums)) return 0;
    if(i == n) return 0;

    vi nums1(nums.size());
    for(int j = 0 ; j < nums.size();j++){
        nums1[j] = nums[j] + parametros[i][j];
    }
    ll pega = solve(i+1,nums1,parametros,c + custos[i],custos);
    ll n_pega = solve(i+1,custos,parametros,c,custos);
    return min(pega,n_pega);
}

int main()
{
    optimize;
    cin >> n >> k >> p;
    vector<vi> parametros(n,vector<int>(k));
    vi custos(n);
    for(int i = 0; i < n;i++){
        cin >> custos[i];
        for(int j = 0; j < k;j++){
            cin >> parametros[i][j];
        }
    }
    vi nums(k);
    cout << solve(0,nums,parametros,0,custos) << endl;
    return 0;
}

