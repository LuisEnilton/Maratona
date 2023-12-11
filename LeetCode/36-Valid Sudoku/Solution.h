//
// Created by Luis on 03/12/2023.
//

#ifndef MARATONA_SOLUTION_H
#define MARATONA_SOLUTION_H
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cmath>
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
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> freq(15,0);
        bool ans = true;
        for(int i = 0 ; i < 9;i++){
            for(int j = 0; j < 9;j++){
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                if(freq[num]) ans = false;
                freq[num]++;
            }
        }
        fill(freq.begin(),freq.end(),0);
        for(int i = 0 ; i < 9;i++){
            for(int j = 0; j < 9;j++){
                if(board[j][i] == '.') continue;
                int num = board[j][i] - '1';
                if(freq[num]) ans = false;
                freq[num]++;
            }
        }
        fill(freq.begin(),freq.end(),0);
        for(int k = 0; k < 9;k++){
            int init = (k / 3 ) * 3;
            for(int i = init;i < init + 3 ; i++){
                int ini = (k % 3) * 3;
                for(int j = ini; j < ini + 3;j++){
                    if(board[i][j] == '.') continue;
                    int num = board[i][j] - '1';
                    if(freq[num]) ans = false;
                    freq[num]++;
                }
            }
        }
        return ans;
    }
};


#endif //MARATONA_SOLUTION_H
