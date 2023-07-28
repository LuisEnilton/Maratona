//
// Created by Luis on 25/07/2023.
//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
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
#define MAXN 200020
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

ll seg[4 * MAXN], nums[MAXN];

ll NEUTRO = INFLL;

ll join(ll a, ll b)
{
    // return a + b;
    return min(a, b);
}

void build(int no, int l, int r)
{
    // estamos buildando um folha
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

void update(int no, int l, int r, int pos, int v)
{
    // chegou na posicao que cê quer mudar
    if (l == r)
    {
        seg[no] = v;
        return;
    }

    int e = 2 * no;
    int d = e + 1;
    int m = (l + r) / 2;

    if (pos <= m)
        update(e, l, m, pos, v);
    else
        update(d, m + 1, r, pos, v);

    seg[no] = join(seg[e], seg[d]);
}

ll query(int no, int l, int r, int a, int b)
{
    //totalmente fora
    if (r < a || b < l)
        // valor neutro (no caso do min, o INF)
        return NEUTRO;

    // totalmente dentro
    if (a <= l && r <= b)
        return seg[no];

    int e = 2 * no;
    int d = e + 1;
    int m = (l + r) / 2;

    return join(query(e, l, m, a, b), query(d, m + 1, r, a, b));

}

int main(int argc, char** argv)
{
    optimize;

    int N, Q;

    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
        cin >> nums[i];

    build(1, 1, N);

    int op, a, b;

    while (Q--)
    {
        cin >> op >> a >> b;

        if (op == 1)
            update(1, 1, N, a, b);
        else
            cout << query(1, 1, N, a, b) << endl;
    }

    return 0;
}