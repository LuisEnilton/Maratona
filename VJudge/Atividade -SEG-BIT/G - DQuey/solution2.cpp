//
// Created by Luis on 30/08/2023.
//
// Created by Luis on 24/07/2023.
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
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>



int n;
const int MAXN = 30010;
set<int> seg[4 * MAXN];
int NEUTRO =0;

set<int> join(set<int> &a, set<int> &b)
{
    a.insert(ALL(b));
    return a;
}


vector<int> nums;
void build(int no, int l, int r)
{
    if (l == r)
    {
        seg[no].insert(nums[l]);
        return;
    }

    int e = 2 * no;
    int d = e + 1;
    int m = (l + r) / 2;

    build(e, l, m);
    build(d, m + 1, r);

    seg[no].insert(ALL(seg[e]));
    seg[no].insert(ALL(seg[d]));
}


set<int> query(int no, int l, int r, int a, int b)
{
    if (l > b || r < a){
        set<int> vazio;
        return vazio;
    }


    if (l >= a && r <= b)
    {
        return seg[no];
    }

    int e = 2 * no;
    int d = e + 1;
    int m = (l + r) / 2;

    set<int> esq = query(e, l, m, a, b);
    set<int> dir = query(d, m + 1, r, a, b);
    return join(esq, dir);
}





int q;
int main(int argc, char **argv) {
    optimize;



    cin >> n ;
    nums.resize(n);
    for(auto &x:nums) cin >> x;
    build(1,0,n-1);
    cin >> q;
    while(q--){
        int l ,r;
        cin >> l >> r;
        l--,r--;
        cout <<  query(1,0,n-1,l,r).size() << endl;
    }

    return 0;
}