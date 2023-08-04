//
// Created by Luis on 12/07/2023.
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
public:
    int static dp [2501];

    Solution(){
        memset(dp,-1,sizeof dp);
    }

    int solve(int q , int i,int maior, vi &nums){
        if(i >= nums.size())
            return q ;

        if(dp[i]!=-1) return dp[i];


        int novo_maior = maior;

        int n_pega;

        int pega = -1;

        if(nums[i] <= maior){
            q--;
            n_pega = (solve(q,i+1,maior,nums));
        }else{
            n_pega = (solve(q,i+1,maior,nums));
            pega = 1 + solve(q  , i+1 , nums[i],nums );
        }


        return  dp[i] = max(pega,n_pega);

    }

    int lengthOfLIS(vector<int>& nums) {
        return solve(0,0,-1, nums);
    }
};

int Solution::dp[2501];

#endif //MARATONA_SOLUTION_H
