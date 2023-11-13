//
// Created by Luis on 12/09/2023.
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
    int minDeletions(string &s) {
        vi freq(26,0);
        bitset<100010> bt;
        bt.flip();
        for(auto c : s){
            freq[c - 'a']++;
        }

        for(auto x : freq){
            bt.reset(abs(100009-x));
        }
        bt.set(100009);
        sort(ALL(freq));
        int anterior = 0;
        int ans = 0;
        int i = upper_bound(ALL(freq),0) - freq.begin();
        for( ; i < 26;i++){
            if(freq[i] == 0) continue;

            if(freq[i]!= anterior){
                anterior = freq[i];
            }else{
                int pos = bt._Find_next(abs(100009-freq[i])) ;
                if(pos != 100009) bt.reset(pos );
                ans+= freq[i] - (100009 - pos);
            }
        }
        return ans;
    }
};


#endif //MARATONA_SOLUTION_H