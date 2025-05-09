//
// Created by Luis on 06/09/2023.
//
// Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 1000000010
#define INFLL 1000000000000000010LL
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
#define MAXN 501
#define MAXL 23
#define EPS 1e-9
#define endl '\n'
#define int ll
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>
int ans = 0;
signed main()
{
    optimize;
    int n, x;
    cin >> n >> x;
    int m = n / 2;
    vi a(m);
    for (auto &y : a)
    {
        cin >> y;
    }
    vi sums;
    for (int i = 0; i < (1 << m); i++)
    {
        int aux = 0;
        for (int j = 0; j < m; j++)
        {
            if (i & (1 << j))
            {
                aux += a[j];
            }
        }
        sums.PB(aux);
    }
    sort(ALL(sums));
    int f = n - m;
    vi b(f);
    for (auto &y : b)
    {
        cin >> y;
    }

    for (int i = 0; i < (1 << f); i++)
    {
        int aux = 0;
        for (int j = 0; j < f; j++)
        {
            if (i & (1 << j))
            {
                aux += b[j];
            }
        }
        ans += upper_bound(ALL(sums), x - aux) - lower_bound(ALL(sums), x - aux);
    }
    cout << ans  << endl;
    return 0;
}