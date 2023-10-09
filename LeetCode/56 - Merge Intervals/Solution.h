//
// Created by Luis on 03/10/2023.
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue<pii> pq;
        for(auto p:intervals){

            int ini = p[0];
            int fin = p[1];
            pq.emplace(-fin,1);
            pq.emplace(-ini,2);
        }
        vector<vi> ans;
        vi interval(2);
        int cnt = 0;
        while(!pq.empty()){
            auto atual = pq.top();
            if(atual.second == 2){
                if(cnt == 0) interval[0] = -atual.first;
                cnt++;
            }else{
                cnt--;
                if(cnt == 0){
                    interval[1] = -atual.first;
                    ans.EB(interval);
                    interval = vi(2);
                }
            }
            pq.pop();
        }
        return ans;
    }
};


#endif //MARATONA_SOLUTION_H
