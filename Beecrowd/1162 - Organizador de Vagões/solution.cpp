//
// Created by Luis on 09/08/2023.
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
const int maxn =51;
int bit[maxn];
int arr[maxn];

void update(int pos,int val){
    while(pos < maxn){
        bit[pos] +=val;
        pos+=(pos & - pos);
    }
}

int query(int pos){
    int ans = 0;
    while(pos > 0){
        ans += bit[pos];
        pos -= (pos & - pos);
    }
    return ans;
}


int main(int argc, char** argv)
{
    optimize;
    int t;
    cin >> t;
    while(t--){
        int l;
        cin >> l;
        memset(bit , 0 ,sizeof bit);
        vi nums(l);
        for(auto &x: nums) cin >> x;
        int ans = 0;
        for(int i = l-1;i>= 0;i--){
            ans += query(nums[i]);
            update(nums[i],1);//aumenta um na frequencia desse cara
        }
        cout <<"Optimal train swapping takes "<< ans <<" swaps."  << endl;
    }
    return 0;
}

