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
// #define MAXN 10000010
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

// int => 32 bool => 000101010101
//0 => 0000000000000
// long long => 64 bool
// int
/*
a => 000101010101
b => 001010100101

*/


int seg[4 * MAXN];

int NEUTRO = 0;

int join(int a, int b)
{
    return a | b;
}

string S;

void build(int no, int l, int r)
{
    if (l == r)
    {
        int c = S[l] - 'a';

        seg[no] |= (1 << c);
        return;
    }

    int e = 2 * no;
    int d = e + 1;
    int m = (l + r) / 2;

    build(e, l, m);
    build(d, m + 1, r);

    seg[no] = join(seg[e], seg[d]);
}

void update(int no, int l, int r, int pos)
{
    // chegou na posicao que cê quer mudar
    if (l == r)
    {
        int c = S[l] - 'a';

        seg[no] ^= (1 << c);

        return;
    }

    int e = 2 * no;
    int d = e + 1;
    int m = (l + r) / 2;

    if (pos <= m)
        update(e, l, m, pos);
    else
        update(d, m + 1, r, pos);

    seg[no] = join(seg[e], seg[d]);
}

int query(int no, int l, int r, int a, int b)
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

    cin >> S;

    int N = S.size();

    S = "$" + S;


    build(1, 1, N);

    int Q, op, pos, l, r;
    char c;

    cin >> Q;

    while(Q--)
    {
        cin >> op;

        if (op == 1)
        {
            cin >> pos >> c;

            // inverte o cara
            update(1, 1, N, pos);
            S[pos] = c;
            //inverte o cara
            update(1, 1, N, pos);
        }
        else
        {
            cin >> l >> r;

            auto freq = query(1, 1, N, l, r);

            int ans = __builtin_popcount(freq);

            cout << ans << endl;
        }
    }

    return 0;
}