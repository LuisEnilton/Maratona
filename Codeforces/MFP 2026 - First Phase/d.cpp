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
    cout.tie(NULL);
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define MAXN 1010101
#define int ll
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

signed main()
{
    optimize;
    int sum = 0;
    int n;
    cin >> n;
    vi a(n);
    for (auto &x : a)
        cin >> x, sum += x;

    vi divi;
    int num = a[0];
    divi.push_back(1);
    divi.push_back(num);
    for (int i = 2; i * i <= num; i++)
    {

        if (num % i == 0)
        {
            divi.push_back(i);
            if (i != num / i)
                divi.push_back(num / i);
        }
    }
    int ans = sum;
    sort(ALL(divi));
    for (auto d : divi)
    {
        // dbg(d);
        int cada = d;
        // 		dbg(cada);
        bool ok = 1;
        for (auto x : a)
        {
            if (x % cada != 0)
                ok = 0;
        }
        // 		dbg(ok);
        if (ok)
        {
            ans = min(ans, sum / cada);
        }
    }
    cout << ans << endl;
    return 0;
}
