//
// Created by Luis on 12/07/2023.
//
// Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define optimize               \
  ios::sync_with_stdio(false); \
  cin.tie(NULL);               \
  cout.tie(NULL)
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101
#define MAXN 10101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>
#ifndef MARATONA_SOLUTION_H
#define MARATONA_SOLUTION_H



int solve(int i, vi &numeros,vi &dp)
{
    if (i > numeros.size()  )
        return 0;

    if(dp[i] != -1 ) return dp[i];

    int pega = numeros[i] + solve(i + 2, numeros,dp);
    int npega = 0 + solve(i + 1, numeros,dp );

    return  dp[i] = max(pega, npega);
}

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        int maior = 0,menor = INF;
        vi numeros(MAXN);
        //vi dp(MAXN, -1);
        for (int n : nums)
        {
            if (n > maior)
                maior = n;
            if(n < menor)
                menor = n;
            numeros[n] += n;
        }
        numeros.resize(maior);
        vi dp(maior + 1,-1);
        return solve(menor, numeros,dp);
    }
};

#endif // MARATONA_SOLUTION_H
