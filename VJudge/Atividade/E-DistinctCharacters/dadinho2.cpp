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

struct Node
{
    int freq[30];

    Node()
    {
        memset(freq, 0, sizeof freq);
    }
};

Node seg[4 * MAXN];

Node NEUTRO;

Node join(Node a, Node b)
{
    Node ans;

    for (int i = 0; i < 30; i++)
        ans.freq[i] = a.freq[i] + b.freq[i];

    return ans;
}

string S;

void build(int no, int l, int r)
{
    if (l == r)
    {
        int c = S[l];

        seg[no].freq[c - 'a'] = 1;
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
        int c = S[l];

        seg[no].freq[c - 'a'] += v;

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

Node query(int no, int l, int r, int a, int b)
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

            update(1, 1, N, pos, -1);
            S[pos] = c;
            update(1, 1, N, pos, 1);
        }
        else
        {
            cin >> l >> r;

            auto freq = query(1, 1, N, l, r);

            int ans = 0;

            for (int i = 0; i < 30; i++)
            {
                // cout << i << ": " << freq.freq[i] << endl;
                ans += (freq.freq[i] > 0);
            }
            // cerr << "----------------------" << endl;

            cout << ans << endl;
        }
    }

    return 0;
}