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
    int static dp[101];
    Solution(){
        memset(dp,-1,sizeof dp);
    }

    int static solve(int i,vi numeros){

        if(i == numeros.size() - 1)
            return numeros[numeros.size() - 1];
        if(i > numeros.size() - 1)
            return 0;// n deu de pegar

        if(dp[i] != -1)
            return  dp[i];
    // 2 1 1

        int pega = numeros[i] + solve(i+2,numeros);
        int n_pega = 0 + solve(i+1,numeros);

        return dp[i] = max(pega,n_pega);
    }

    int static rob(vector<int>& nums) {
        int i = 0 ;
        int total = 0;
        return solve(i,nums);
    }
};

int Solution::dp[101];

#endif //MARATONA_SOLUTION_H
