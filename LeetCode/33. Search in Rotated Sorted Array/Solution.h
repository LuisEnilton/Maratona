//
// Created by Luis on 08/08/2023.
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
    int static findInit(vi &nums,int sz,int val){
        int l =0,r = sz-1,mid;
        int ans;
        while(l <=r){
            mid = (l+r)/2;
            if(nums[mid] < val){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }

    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        int ini;
        ini = findInit(nums,sz,nums[0]);
        int end = sz + ini-1;
        int mid;
        while(ini <=end){
            mid = (ini + end)/2;
            int idxMid = mid % sz;
            if(nums[idxMid] == target){
                return idxMid;
            }else if(nums[idxMid] > target){
                end = mid -1;
            }else{
                ini = mid +1;
            }
        }
        return -1;
    }
};


#endif //MARATONA_SOLUTION_H
