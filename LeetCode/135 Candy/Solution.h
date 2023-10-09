//
// Created by Luis on 13/09/2023.
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
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        vi ans(n + 1, 0);
        vi ps(n+1,0);
        ps[0] = 1,ps[1] = -1;
        vi difs(n - 1);
        for (int i = 1; i < n; i++) {
            difs[i - 1] = ratings[i] - ratings[i - 1];
        }
        pii cp = {0, 1};
        int cntP = 0,cntN = 0;
        for (int i = 1; i < n; i++) {
            if (difs[i] < 0) {
                cntN++;
                if(cntN == 0){
                    cp = {i - 1, ps[i - 1]};
                    cntP = 0;
                }
                    if(cntN == cp.second ){
                        ps[cp.first]++;
                        cp.second++;
                        ps[i+1]--;
                    }else{
                        ps[cp.first+1]++;
                        ps[i+1]--;
                    }
            } else if (difs[i] == 0) {

            } else {
                    ps[i] = ps[i-1]+1;
                    cntN = 0;
                    cntP++;
            }
        }

    }
};


#endif //MARATONA_SOLUTION_H
