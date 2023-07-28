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

pii seg[4 * MAXN];
int nums[MAXN];

pii NEUTRO = pii(0, 0);

pii join(pii a, pii b)
{
    pii ans = pii(0, 0);

    int gcd = __gcd(a.first, b.first);

    ans.first = gcd;

    if (gcd == a.first)
        ans.second += a.second;

    if (gcd == b.first)
        ans.second += b.second;

    return ans;
}

void build(int no, int l, int r)
{
    if (l == r)
    {
        seg[no] = pii(nums[l], 1);
        return;
    }

    int e = 2 * no;
    int d = e + 1;
    int m = (l + r) / 2;

    build(e, l, m);
    build(d, m + 1, r);

    seg[no] = join(seg[e], seg[d]);
}

pii query(int no, int l, int r, int a, int b)
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

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> nums[i];

    build(1, 1, N);

    cin >> Q;

    int l, r;

    while(Q--)
    {
        cin >> l >> r;

        int cnt = r - l + 1;

        auto [gcd, freq] = query(1, 1, N, l, r);

        cout << cnt - freq << endl;
    }

    return 0;
}