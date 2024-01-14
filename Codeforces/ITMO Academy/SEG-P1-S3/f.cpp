//
// Created by Luis on 28/12/2023.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cmath>

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
            seg[no] = 1;
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

void comp(vector<ll> &v,vector<pair<ll,ll>> &pares){
    vector<ll>aux = v;
    sort(ALL(aux));
    UNIQUE(aux);
    for(auto & x : pares){
        x.first = POS(aux,x.first);
        x.second = POS(aux,x.second);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<ll> nums(2 * n);
    vector<pair<ll,ll>> pares;
    auto *seg = new SegTree(nums);
    vector<ll> aux;
    for (int i = 0; i <  n; i++) {
        ll l,r; cin >> l >> r;
        pair<ll,ll> par = {r,l};
        pares.EB(par);
        aux.EB(l);
        aux.EB(r);
    }
    comp(aux,pares);
    sort(ALL(pares));
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        auto [r, l] = pares[i];
        ll qry = seg->query(1, 1, 2 * n, l + 1, r + 1);
        ans += qry;
        seg->update(1, 1, 2 * n, l + 1);
    }
    cout << ans << endl;
}

int main() {
    optimize;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

