//
// Created by Luis on 10/11/2023.
//
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







#ifndef MARATONA_SOLUTION_H
#define MARATONA_SOLUTION_H


class Solution {
public:
    void associate(unordered_map<int,int> &identifier,int num,int &id,unordered_map<int,int> &back){
        if(identifier.count(num)) return;
        identifier[num] = id;
        back[id] = num;
        id++;
    }

    void dfs(int u,vector<int> &ans,vector<vector<int>> &graph,vector<bool> &visited,unordered_map<int,int> &back){
        ans.push_back(back[u]);
        visited[u] = true;
        for(auto v : graph[u]){
            if(!visited[v])
                dfs(v,ans,graph,visited,back);
        }
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size();
        unordered_map<int,int> identifier,back;
        int id = 1;
        vector<vector<int>> graph(n + 5);
        int o;
        for(auto pair : adjacentPairs ){
            int x = pair[0],y = pair[1];
            associate(identifier,x,id,back);
            associate(identifier,y,id,back);
            graph[identifier[x]].push_back(identifier[y]);
            graph[identifier[y]].push_back(identifier[x]);
        }
        for(int i = 1; i <=n;i++){
            if(graph[i].size() == 1){
                o = i;
                break;
            }
        }
        vector<int> ans;
        vector<bool> visited(n+5,false);
        dfs(o,ans,graph,visited,back);
        return ans;
    }
};


#endif //MARATONA_SOLUTION_H
