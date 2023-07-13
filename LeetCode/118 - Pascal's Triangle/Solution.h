//
// Created by luise on 13/07/2023.
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
    vector<vector<int>> static linhas;
    Solution(){
        linhas.clear();
    }
    void solve(int linha, int n){
        if(linha == n ) return;
        if(n == 1) return ;
        if(linha == 1) {
            linhas[1].EB(1);
            linhas[1].EB(1);
        }else{
            linhas[linha].EB(1);
            for (int i = 1; i <= linha-1; i++) {
                int ele = linhas[linha-1][i-1] + linhas[linha-1][i];
                linhas[linha].EB(ele);

            }
            linhas[linha].EB(1);

        }
        solve(linha+1,n);
    }

    vector<vector<int>> generate(int numRows) {
        linhas.resize(numRows);
        linhas[0].EB(1);
        if(numRows == 1) return linhas;
        solve(1,numRows);
        return linhas;
    }
};

vector<vector<int>> Solution::linhas;


#endif //MARATONA_SOLUTION_H
