//
// Created by luise on 20/07/2023.
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
    int solve(int i , int j , vector<vector<char>> &matrix,vector<vi> &dp ){
        if(i < 0 || j < 0)
            return INF;
        if(matrix[i][j] == 0 || (i == 0 && j == 0))
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int esq = solve(i,j-1,matrix,dp);
        int cima = solve(i - 1,j,matrix,dp);
        int diag = solve(i-1,j-1,matrix,dp);

        return dp[i][j] = 1 + min(min(esq,cima),diag);
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vi> dp (matrix.size(),vi(matrix[0].size(),-1));
        return solve(matrix.size()-1,matrix[0].size()-1,matrix,dp);
    }
};


#endif //MARATONA_SOLUTION_H
