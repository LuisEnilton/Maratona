//
// Created by Luis on 19/07/2023.
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
    int longestPalindrome(string s) {
        map<char,int> letras;
        for(char c : s){
            if(letras.count(c) == 0)
                letras[c] = 1;
            else
                letras[c]++;
        }
        priority_queue<pair<int,char>> pq;
        int ans = 0;
        for(auto x : letras){
            pq.emplace(x.second,x.first);
        }
        bool impar = false;
        while(!pq.empty()){
            auto top = pq.top();
            if(top.first%2 != 0 ){
                if(!impar){
                    ans += top.first;
                    impar = true;
                }
                else
                    ans += top.first -1;

            }
            if(top.first%2 == 0){
                ans += top.first;
            }
            pq.pop();
        }


        return ans;
    }
};


#endif //MARATONA_SOLUTION_H
