//
// Created by Luis on 22/09/2023.
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

    vector<int> pi(string &t){
        vector<int> p(t.size(), 0);

        for(int i=1, j=0; i<t.size(); i++)
        {
            while(j > 0  && t[j] != t[i]) j = p[j-1];

            if(t[j] == t[i]) j++;

            p[i] = j;
        }

        return p;
    }

    vector<int> kmp(string &s, string &t){
        vector<int> p = pi(t), occ;

        for(int i=0, j=0; i<s.size(); i++)
        {
            while( j > 0 && s[i] != t[j]) j = p[j-1];

            if(s[i]==t[j]) j++;

            if(j == t.size()) occ.push_back(i-j+1), j = p[j-1];
        }

        return occ;
    }

    bool isSubsequence(string &s, string &t) {
            int i = 0;
            for(int j = 0; j < t.size();j++){
                if(s[i] == t[j]){
                    i++;
                    if(i == s.size()) return true;
                }
            }
            return false;

    }
};


#endif //MARATONA_SOLUTION_H
