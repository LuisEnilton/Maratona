//
// Created by Luis on 25/09/2023.
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

int main(int argc, char** argv)
{
    optimize;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> nums1(n),nums2(n);
        ll ans1 = INF;
        ll sum1 = 0;
        for(auto &x : nums1){
            cin >> x;
            ans1 = min(ans1,x);
            sum1+=x;
        }
        ll sum2 = 0;
        ll ans2 = INF;
        for(auto &x: nums2){
            cin >> x;
            ans2 = min(ans2,x);
            sum2+=x;
        }

        if(sum1 + n*ans2 > sum2 + n * ans1){
            cout << sum2 + n*ans1 << endl;
        }else{
            cout << sum1 + n*ans2 << endl;
        }

    }
    return 0;
}

/*
 13
2 7 1 5 7 5 4 4 10 7 2 1 2
4 6 10 4 1 4 4 2 3 9 3 9 1


 1 1 2
 3 1 4
 * */