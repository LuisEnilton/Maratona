//
// Created by Luis on 23/01/2024.
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
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<vector<int>> freq(n,vector<int>(26));
        for(int i = 0; i < n;i++){
            for(auto c : arr[i]){
                freq[i][int(c-'a')]++;
            }
        }
        int ans = 0;
        for(int i = 1;i < (1 << n);i++){
            int sz = 0;
            bool ok = true;
            vector<int> aux(26);
            for(int k = 0;k < n;k++) if((1 << k) & i){
                    cout << i << endl;
                    sz+= arr[k].size();
                }
            for(int j = 0; j < 26 && ok ; j++){
                for(int k = 0;k < n && ok;k++) if((1 << k) & i){
                        if(aux[j] > 0) ok = false;
                        aux[j]+=freq[k][j];
                    }
            }
            if(!ok) continue;
            ans = max(ans,sz);
        }
        return ans;
    }
};


#endif //MARATONA_SOLUTION_H
