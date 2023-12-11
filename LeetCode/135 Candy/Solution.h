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
        vi ps(n, 1);
        vi ans;
        int ans1 = 0;
        vector<bool> reseta(n, false);
        bool crescendo = ratings[1] > ratings[0];
        for (int r = 1, l = 0; r < n; r++) {
            if (ratings[r] > ratings[r - 1]) {
                l = r;
                crescendo = true;
                continue;
            }
            ps[l]++;
            ps[r]--;
            reseta[r] = true;
            if (crescendo) l = r;
            crescendo = false;
        }
        for (int i = 0, sum = 0; i < n; i++) {
            if (reseta[i]) {
                if (ans[i - 1] > 2) {
                    ans[i - 1]--;
                }
                sum = 1;
            }
            sum += ps[i];
            ans.push_back(sum);
            ans1+=sum;
        }
        for (auto x: ans) {
            cout << x << " ";
        }
        return ans1;
    }
};


#endif //MARATONA_SOLUTION_H
