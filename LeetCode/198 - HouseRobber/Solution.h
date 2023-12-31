//
// Created by Luis on 12/07/2023.
//
#ifndef MARATONA_SOLUTION_H
#define MARATONA_SOLUTION_H
//template by
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
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



class Solution {
public:
    int rob(vector<int>& nums) {
        // robber and no robber
        int n = nums.size();
        int dp[n][2]; // end with i
        for (auto d : dp) {
            d[0] = 0;
            d[1] = 0;
        }

        dp[0][0] = nums[0];
        // o [1] vai guardar o maximo que eu consigo sem pegar o atual
        for (int i = 1; i < n; i++) {
            //se eu roubo eu pego o max sem roubar a passada e roubo essa
            dp[i][0] = dp[i-1][1] + nums[i];
            // seu n roubo eu escolho o max entre roubar a passada e m roubar,pq n vai ativar alarme de nenhum jeito
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]);// max entre pegar e n pegar do passado
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};

#endif //MARATONA_SOLUTION_H
