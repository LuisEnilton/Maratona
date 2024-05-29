//
// Created by Luis on 16/09/2023.
//
//
// Created by Luis on 16/09/2023.
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
    ll NEUTRO = 0;

    SegTree(vector<ll> &nums) {
        n = nums.size();
        seg.resize(4 * n);
        this->nums = nums;

        build(1, 1, n);
    }

    SegTree(int n) {
        this->n = n;
        seg.resize(4 * n);
        this->nums = vector<ll>(n,1);
        build(1,1,n);
    }

    ll join(ll a, ll b) {

        return a + b;
    }

    void build(int no, int l, int r) {
        if (l == r) {
            seg[no] = *new ll(nums[l - 1]);
            return;
        }

        int e = 2 * no;
        int d = e + 1;
        int mid = (l + r) / 2;
        build(e, l, mid);
        build(d, mid + 1, r);
        seg[no] = join(seg[e], seg[d]);
    }

    void update(int no, int l, int r, int pos, ll val) {
        if (r < pos || l > pos) {
            return;
        }

        if (l == r) {
            seg[no] = val;
            return;
        }

        int e = 2 * no;
        int d = e + 1;
        int mid = (l + r) / 2;
        update(e, l, mid, pos, val);
        update(d, mid + 1, r, pos, val);

        seg[no] = join(seg[e], seg[d]);
    }

    ll query(int no, int l, int r, int &k) {
        if(k>=seg[no]){
            k-=seg[no];
            return 0;
        }

        if (l == r) {
            return l;
        }
        int e = 2 * no;
        int d = e + 1;
        int mid = (l + r) / 2;
        ll dir = query(d,mid+1,r,k);
        ll esq = NEUTRO;
        if(dir == NEUTRO){
            esq = query(e,l,mid,k);
        }
        return join(dir,esq);
    }
};


int main(int argc, char **argv) {
    optimize;
    int n;
    cin >> n;
    auto seg = *new SegTree(n);
    vi inv;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        inv.EB(num);
    }
    stack<int> ans;
    for(int i = n-1;i>=0;i--){
        ll index =  seg.query(1, 1, n, inv[i]) ;
        ans.push(index);
        seg.update(1,1,n,index,-1
        );
    }
    while(!ans.empty()){
        int idx = ans.top();
        ans.pop();
        cout << idx << " ";
    }
    cout << endl;
    return 0;
}

