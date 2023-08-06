//
// Created by Luis on 05/08/2023.
//

#ifndef MARATONA_SOLUTION_H
#define MARATONA_SOLUTION_H
//
// Created by Luis on 04/08/2023.
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


vi manacher(string &st) {
    string s = "$_";
    for (auto c: st) {
        s += c;
        s += "_";
    }
    s += "#";
    int n = s.size() - 2; //elimina o '$' e o '#'
    vi p(n + 2);
    int l = 1, r = 1;// r marca o palindromo que chegou mais longe
    for (int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + r - i]));

        while (s[i - p[i]] == s[i + p[i]])//tenta crescer pros 2 lados
            p[i]++;

        if (i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
    }

    for (auto &x: p) x--;
    return p;
}

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        for(int i =0;i < n;i++){
            for(int j =i+1;j < n;j++){
                int sz1 = words[i].size();
                int sz2 = words[j].size();
                 string copy = words[i];
                 copy += words[j];
                 vi p = manacher(copy);
                //$_a_b_c_# 2 + n-1
                string copy2 = words[j];
                copy2 += words[i];
                vi p2 = manacher(copy2);
            }
        }
    }
};


#endif //MARATONA_SOLUTION_H
