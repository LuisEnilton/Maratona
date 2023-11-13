//
// Created by Luis on 27/09/2023.
//
//
// Created by Luis on 14/09/2023.
//
#include <bits/stdc++.h>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int, int>
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

#define dbg_loc() cerr << __PRETTY_FUNCTION__ << " : " << __LINE__ << "\n"

template<typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
    os << '{';
    string sep;
    for (const T &x: v)
        os << sep << x, sep = ", ";
    return os << '}';
}

void dbg_out() { cerr << endl; }

template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}

#define LOCAL
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__), cerr << endl
#else
#define dbg(...)
#endif

struct SegTree {
    vector<ll> seg, lazy, nums;
    ll NEUTRO = 0;
    int n;

    SegTree(vector<ll> &nums) {
        n = nums.size();
        seg.resize(4 * n);
        lazy.resize(4 * n);

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
        int m = (l + r) / 2;

        build(e, l, m);
        build(d, m + 1, r);

        seg[no] = join(seg[e], seg[d]);
    }

    void atualiza(int no, ll v) {
        lazy[no] = v;
    }

    void unlazy(int no, int l, int r) {
        if (lazy[no] == 0) return;

        int m = (l + r) >> 1, e = no * 2, d = no * 2 + 1;

        seg[no] = 1LL * (r - l + 1) * lazy[no];

        if (l != r) {
            lazy[e] = lazy[no];
            lazy[d] = lazy[no];
        }

        lazy[no] = 0;
    }

    void update(int no, int l, int r, int a, int b, ll v) {
        unlazy(no, l, r);
        if (r < a || l > b)
            return;

        if (a <= l && r <= b) {
            atualiza(no, v);
            unlazy(no, l, r);
            return;
        }

        int e = 2 * no;
        int d = e + 1;
        int m = (l + r) / 2;

        update(e, l, m, a, b, v);
        update(d, m + 1, r, a, b, v);

        seg[no] = join(seg[e], seg[d]);
    }

    ll query(int no, int l, int r, int a, int b) {
        unlazy(no, l, r);
        if (r < a || l > b)
            return NEUTRO;

        if (a <= l && r <= b) {
            return seg[no];
        }

        int e = 2 * no;
        int d = e + 1;
        int m = (l + r) / 2;

        return join(query(e, l, m, a, b), query(d, m + 1, r, a, b));
    }
};

int main(int argc, char **argv) {
    optimize;

    int n, m;
    cin >> n >> m;
    vector<ll> nums(n);
    auto seg = *new SegTree(nums);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            ll val;
            cin >> l >> r >> val;
            l++, r++;
            seg.update(1, 1, n, l, r - 1, val);
        } else {
            int pos;
            cin >> pos;
            cout << seg.query(1, 1, n, pos + 1, pos + 1) << endl;
        }
    }

    return 0;
}

/*
5 5
1 0 3 3
2 2
1 2 4 4
2 2
2 1

 * */