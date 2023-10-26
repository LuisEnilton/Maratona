//
// Created by luise on 25/10/2023.
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




int main()
{
    optimize;
    int n;
    ll x;
    cin >> n >> x;
    vector<pair<ll,int>> nums(n);
    for(int i = 0; i < n;i++){
        cin >> nums[i].first;
        nums[i].second = i + 1;
    }
    sort(ALL(nums));
    for(int i = 0; i < n;i++){
        ll val = x - nums[i].first;
        int l = i+1,r = n-1;
        bool ok = false;
        while(l<r){
            ll sum = nums[l].first + nums[r].first;
            if(sum == val){
                ok = true;
                break;
            }else if(sum > val){
                r--;
            }else{
                l++;
            }
        }
        if(ok){
            cout << nums[i].second << " " << nums[l].second << " "<< nums[r].second << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}

