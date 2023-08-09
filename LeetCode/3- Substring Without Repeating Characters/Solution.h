//
// Created by luise on 09/08/2023.
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
        int lengthOfLongestSubstring(string s) {
            set<char> letters;
            int n = s.size();
            int l , r;
            int ans = 0;
            for(int i =0 , l = 0, r = -1;i < n;i++){
                    int initSz ;
                    do{
                        r++;
                        if(r >= n) break;
                        initSz = letters.size();
                    letters.insert(s[r]);
                    }while(letters.size() > initSz);
                        if(r >= n){
                             ans = max(ans , r -l );
                             break;
                        }
                    r--;
                    ans = max(ans , r -l + 1);
                        while(s[l] != s[r + 1]){
                            letters.erase(s[l]);
                            l++;
                        }
                        letters.erase(s[l]);
                    l++;
            }
            return ans;
        }
}


#endif //MARATONA_SOLUTION_H
