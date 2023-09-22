//
// Created by Luis on 17/09/2023.
//
//
// Created by Luis on 17/09/2023.
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

struct Node{

    ll open;
    ll close;
    ll done;

    Node(){
        this->open = 0;
        this->close = 0;
        this->done = 0;
    }

    Node(char c){
        if(c == '('){
            this->open = 1;
            this->close = 0;
        }else{
            this->open = 0;
            this->close = 1;
        }
        this->done = 0;
    }


};



struct SegTree {
    int n;
    vector<ll> nums;
    vector<ll> seg;
    ll NEUTRO = INF;

    SegTree(const vector<ll>& nums) {
        n = nums.size();
        seg.resize(4 * n);
        this->nums = nums;

        build(1, 1, n);
    }

    ll join(ll a, ll b) {
        return min(a,b);
    }

    void build(int no, int l, int r) {
        if (l == r) {
            seg[no] = nums[l-1];
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

    ll query(int no, int l, int r, int a, int b) {
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
    int t; cin >> t;
    for(int i = 1;i <=t;i++){
        cout << "Scenario #" << i << ":" << endl;
        int m,n;
        cin >> n >> m;
        vector<ll> nums(n);
        for(auto &x:nums) cin >> x;
        auto *seg = new SegTree(nums);
        while(m--){
            int l ,r;
            cin >> l >> r;
            ll ans = seg->query(1,1,n,l,r);
            cout << ans << endl;
        }
    }
    return 0;
}

