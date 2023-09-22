//
// Created by Luis on 18/09/2023.
//
//
// Created by Luis on 18/09/2023.
//
//
// Created by Luis on 15/09/2023.
//
//
// Created by Luis on 15/09/2023.
//
//
// Created by Luis on 15/09/2023.
//
//
// Created by Luis on 15/09/2023.
//
//
// Created by Luis on 15/09/2023.
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


struct SegTree {
    int n;
    vector<ll> nums;
    vector<ll> seg;
    ll NEUTRO = 0LL;

    SegTree(vector<ll> &nums) {
        n = nums.size();
        seg.resize(4 * n);
        this->nums = nums;

        build(1, 1, n);
    }

    ll join(ll a, ll b) {
        return a + b;
    }

    void build(int no, int l, int r) {
        if (l == r) {
            seg[no] = nums[l - 1];
            return;
        }

        int e = 2 * no;
        int d = e + 1;
        int mid = (l + r) / 2;
        build(e, l, mid);
        build(d, mid + 1, r);
        seg[no] = join(seg[e], seg[d]);
    }

    void update(int no, int l, int r, int pos) {
        if (r < pos || l > pos) {
            return;
        }

        if (l == r) {
            int arr[2] = {1,0};
            seg[no] = arr[seg[no]];
            return;
        }

        int e = 2 * no;
        int d = e + 1;
        int mid = (l + r) / 2;
        update(e, l, mid, pos);
        update(d, mid + 1, r, pos);

        seg[no] = join(seg[e], seg[d]);
    }

    ll query(int no, int l, int r, int a, int b) {

        if (b < l || a > r) {
            return NEUTRO;
        }

        if (l >= a && r <= b) {
            return seg[no];
        }


        int e = no * 2;
        int d = e + 1;
        int mid = (l + r) / 2;
        ll esq = query(e, l, mid, a, b);
        ll dir = query(d, mid + 1, r, a, b);
        return join(esq, dir);
    }
};


int main(int argc, char **argv) {
    optimize;
    int n;
    cin >> n;
    vector<ll> nums(2 * n);
    vector<int> ocurrences(n + 1,-1);
    auto *seg = new SegTree(nums);
    for (int i = 0; i < 2 * n; i++) {
        ll num;
        cin >> num;
        nums[i] = num;
    }
    vector<ll> ans(n);
    for(int i = 0; i <2*n;i++){

        if(ocurrences[nums[i]] == -1){
            seg->update(1,1,2*n,i+1);
            ocurrences[nums[i]] = i;
        }else{
            seg->update(1,1,2*n,ocurrences[nums[i]] + 1);
            ll qry = seg->query(1,1,2*n,ocurrences[nums[i]] + 1,i+1);
            ans[nums[i]-1] += qry;
        }
    }
    ocurrences = vector<int>(n+1,-1);
    for(int i = 2*n-1;i >=0;i--){
        if(ocurrences[nums[i]] == -1){
            seg->update(1,1,2*n,i+1);
            ocurrences[nums[i]] = i;
        }else{
            seg->update(1,1,2*n,ocurrences[nums[i]] + 1);
            ll qry = seg->query(1,1,2*n,i+1,ocurrences[nums[i]] + 1);
            ans[nums[i] - 1] += qry;
        }
    }
    for(auto x : ans){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

