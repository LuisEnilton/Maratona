//
// Created by Luis on 21/10/2023.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>
#include <iostream>
#include <ranges>
#include <string_view>
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
    int x,n;
    cin >> x >> n;
    set<int> nums;
    for(int i = 0; i < n; i ++){
        int val; cin >> val;
        int sup,inf;
        auto it = nums.upper_bound(val);
        if(it == nums.end()) sup = x;
        else sup = *it;

        it = nums.lower_bound(val);
        if(it == nums.end()){
            if(it != nums.begin()){
                it--;
                inf = *it;
            }else{
                inf = 0;
            }
        }else{
            if(it == nums.begin()){
                inf = 0;
            }else{
                inf = *it;
            }
        }
        nums.insert(val);
        cout << max({abs(val - inf),abs(val-sup),x - *nums.rbegin(),*nums.begin()}) << " ";
    }

    return 0;
}

