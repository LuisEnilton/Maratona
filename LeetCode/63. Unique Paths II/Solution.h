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
    int solve(int i, int j, vector<vi > &grid, vector<vi > &dp) {
        cout << i << " " << j << endl;
        if (i == 0 && j == 0) return 1;

        if (grid[i][j] == 1) return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (i > 0 && j > 0) {
            return dp[i][j] = solve(i - 1, j, grid,dp) + solve(i, j - 1, grid,dp);
        } else if (i == 0) {
            return dp[i][j] = solve(i, j - 1, grid,dp);
        } else
            return dp[i][j] = solve(i - 1, j, grid,dp);


    }


    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int iniciox = obstacleGrid.size() - 1;
        int inicioy = obstacleGrid[0].size() - 1;
        vector<vi > dp(iniciox + 1, vi(inicioy + 1, -1));
        return solve(iniciox, inicioy, obstacleGrid, dp);
    }
};


#endif //MARATONA_SOLUTION_H
