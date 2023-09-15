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
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p)
{
    return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#define LOCAL
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__), cerr << endl
#else
#define dbg(...)
#endif

struct SegTree
{
    vector<ll> seg, lazy, nums;
    ll NEUTRO = 0;
    int N;

    SegTree(vector<ll> &nums)
    {
        int N = nums.size();
        seg.resize(4 * N);
        lazy.resize(4 * N);

        this->nums = nums;

        build(1, 0, N - 1);
    }

    ll join(ll a, ll b)
    {
        return a + b;
    }

    void build(int no, int l, int r)
    {
        if (l == r)
        {
            seg[no] = nums[l];
            return;
        }

        int e = 2 * no;
        int d = e + 1;
        int m = (l + r) / 2;

        build(e, l, m);
        build(d, m + 1, r);

        seg[no] = join(seg[e], seg[d]);
    }

    void atualiza(int no, ll v)
    {
        lazy[no] += v;
    }

    void apply(int no, int l, int r)
    {
        seg[no] += (lazy[no] * (r - l + 1));

        if (l != r)
        {
            int e = 2 * no;
            int d = e + 1;

            atualiza(e, lazy[no]);
            atualiza(d, lazy[no]);
        }

        // CUIDADO COM ESSE VALOR, COLOCAR UM VALOR NEUTRO.
        lazy[no] = 0;
    }

    void update(int no, int l, int r, int a, int b, ll v)
    {
        apply(no, l, r);
        if (r < a || l > b)
            return;

        if (a <= l && r <= b)
        {
            atualiza(no, v);
            apply(no,l,r);
            return;
        }

        int e = 2 * no;
        int d = e + 1;
        int m = (l + r) / 2;

        update(e, l, m, a, b, v);
        update(d, m + 1, r, a, b, v);

        seg[no] = join(seg[e], seg[d]);
    }

    ll query(int no, int l, int r, int a, int b)
    {
        apply(no, l, r);
        if (r < a || l > b)
            return NEUTRO;

        if (a <= l && r <= b)
        {
            return seg[no];
        }

        int e = 2 * no;
        int d = e + 1;
        int m = (l + r) / 2;

        return join(query(e, l, m, a, b), query(d, m + 1, r, a, b));
    }
};

int main(int argc, char **argv)
{
    optimize;

    int N, M;

    cin >> N >> M;

    vector<ll> nums(N, 0);

    SegTree seg(nums);

    int op, l, r, v;

    while (M--)
    {
        cin >> op;

        if (op == 1)
        {
            cin >> l >> r >> v;

            seg.update(1, 0, N - 1, l, r - 1, v);
        }
        else
        {
            cin >> v;

            cout << seg.query(1, 0, N - 1, v, v) << endl;
        }
    }

    return 0;
}