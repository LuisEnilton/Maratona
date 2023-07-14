//
// Created by Luis on 14/07/2023.
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
#ifndef MARATONA_SOLUTION_H
#define MARATONA_SOLUTION_H


class Solution {
    int static dp [1000];
public:
    Solution(){
        memset(dp,-1,sizeof dp);
    }
    int solve(int d , vector<int> cost){
        if(d > cost.size())
            return INF;// se passou do final não é um caminho possivel

        if(d == cost.size())
            return 0;

        if(dp[d] != -1)
            return dp[d];

        return dp[d] = min(cost[d] + solve(d+1,cost),cost[d] + solve(d+2,cost));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        return min(solve(0,cost),solve(1,cost));
        //pode começar já pulando 1 por isso min
    }
};

int Solution::dp[1000];

#endif //MARATONA_SOLUTION_H
