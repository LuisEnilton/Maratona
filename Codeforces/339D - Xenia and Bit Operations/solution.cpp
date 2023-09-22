//
// Created by Luis on 18/09/2023.
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


struct Node {
    ll val;
    bool par;

    Node() {
        this->val = 0;
        this->par = 0;
    }

    Node(ll v, bool p) {
        this->val = v;
        this->par = p;
    }
};


struct SegTree {
    int n;
    bool parity;
    vector<ll> nums;
    vector<Node> seg;
    Node NEUTRO = *new Node();

    SegTree(vector<ll> &nums, int level) {
        n = nums.size();
        this->parity = level & 1;
        seg.resize(4 * n);
        this->nums = nums;

        build(1, 1, n);
    }

    Node join(Node a, Node b) {
        Node ans;
        if (a.par == this->parity) {
            ans.val = a.val | b.val;
        } else {
            ans.val = a.val ^ b.val;
        }
        ans.par = !a.par;
        return ans;
    }

    void build(int no, int l, int r) {
        if (l == r) {
            seg[no] = *new Node(nums[l - 1], this->parity);
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
            seg[no].val = val;
            return;
        }

        int e = 2 * no;
        int d = e + 1;
        int mid = (l + r) / 2;
        update(e, l, mid, pos, val);
        update(d, mid + 1, r, pos, val);

        seg[no] = join(seg[e], seg[d]);
    }

    Node query(int no, int l, int r, int a, int b) {
        if (r < a || l > b) {
            return NEUTRO;
        }

        if (l >= a && r <= b) {
            return seg[no];
        }
        int e = 2 * no;
        int d = e + 1;
        int mid = (l + r) / 2;
        return join(query(e, l, mid, a, b), query(d, mid + 1, r, a, b));
    }
};


int main(int argc, char **argv) {
    optimize;
    int n, m;
    cin >> n >> m;
    vector<ll> nums(1<<n);
    for(auto &x: nums){
        cin >> x;
    }
    int sz = 1 << n;
    auto seg = *new SegTree(nums,n);
    while(m--){
        int p;
        ll b;
        cin >> p >> b;
        seg.update(1,1,sz,p,b);
        cout << seg.query(1,1,sz,1,sz).val << endl;
    }
    return 0;
}

