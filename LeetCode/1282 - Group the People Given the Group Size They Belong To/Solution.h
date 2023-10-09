//
// Created by Luis on 11/09/2023.
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
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<pair<int,int>> peoples;

        for(int i = 1;i <=n;i++){
            peoples.push_back({groupSizes[i-1],i-1});
        }
        sort(ALL(peoples));
        vector<vi> ans;
        int atual = -1;
        vi group;
        for(int i = 0; i < n;i++){
            if(peoples[i].first!=atual){
                if(i!=0){
                    ans.push_back(group);
                    group.clear();
                }
                group.push_back(peoples[i].second);
            }else{
                if(group.size() == atual){
                    ans.push_back(group);
                    group.clear();
                }
                group.push_back(peoples[i].second);
            }
            atual = peoples[i].first;
        }
        ans.push_back(group);
        return ans;
    }
};


#endif //MARATONA_SOLUTION_H
