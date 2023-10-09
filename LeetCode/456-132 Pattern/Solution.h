//
// Created by Luis on 30/09/2023.
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



struct BIT {
    int bit[MAXN]{};

    BIT(){
        memset(bit, 0, sizeof bit);
    }


    void update(int pos, int val){
        for(; pos < MAXN; pos += pos&(-pos))
            bit[pos] += val;
    }

    int query(int pos){
        int sum = 0;
        for(; pos > 0; pos -= pos&(-pos))
            sum += bit[pos];
        return sum;
    }


} ;


class Solution {
public:



    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vi copy = nums;
        int maxn = 2 * 10e5+ 2;
        sort(ALL(copy));
        UNIQUE(copy);
        for(auto &x:nums){
            x = POS(copy,x) ;
        }
        auto bit = *new BIT();
        for(int i = 0; i < n;i++){
            int qtdMenor = bit.query(nums[i] - 1);
            int qtdMaior = bit.query(maxn) - bit.query(nums[i]);
            if(qtdMenor > 0 && qtdMaior > 0) return true;
        }
        return false;
    }
};


#endif //MARATONA_SOLUTION_H
