//
// Created by luise on 04/10/2023.
//

#ifndef MARATONA_SOLUTION_H
#define MARATONA_SOLUTION_H
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




class Solution {
public:

    int solve(int i,vector<int> &dp,vector<int> &nums){
        if(i >= nums.size()){
            return INF; // passou do objetivo,retorna INF pra indicar erro
        }

        if(i == nums.size() - 1) return 0;//deu bom,n tem mais oq fzer

        if(dp[i] != -1) return dp[i];

        int ans = INF;
        for(int j = 1 ; j <= nums[i];j++ ){ // tem que testar todas as combinações de pulo de 1 até nums[i];
            ans = min(1 + solve( i + j , dp , nums ) , ans);
        }
        return dp[i] = ans;
    }

    bool jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(0,dp,nums);
    }
};


#endif //MARATONA_SOLUTION_H
