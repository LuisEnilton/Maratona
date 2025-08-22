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
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>
#define BT bitset<500>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define MAXN 400010
#define int ll
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

signed main()
{
    optimize int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vi> ps(n + 1, vi(26));

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < 26; j++)
        {
            ps[i + 1] = ps[i];
        }

        ps[i + 1][s[i] - 'a']++;
    }

    // for (int j = 0; j < 26; j++)
    // {
    //     for (int i = 0; i <= n; i++)
    //     {
    //         cout << ps[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    string ans = "*";
    for (int sz = 1; sz <= n / 2; sz++)
    {
        if (n % sz != 0)
            continue;
        vi quant(26);

        for (int i = 0; i < 26; i++)
        {
            quant[i] = ps[sz][i] - ps[0][i];
        }
        // for (int i = 0; i < 26; i++)
        // {
        //     cout << quant[i] << " ";
        // }
        // cout << endl;
        bool ok = 1;
        for (int i = sz; i < n; i += sz)
        {

            vi aux(26);
            for (int j = 0; j < 26; j++)
            {
                aux[j] = ps[i + sz][j] - ps[i][j];
            }

                        if (aux != quant)
            {
                ok = 0;
                break;
            }
        }
        if (!ok)
            continue;
        ans = s.substr(0, sz);
        break;
    }
    cout << ans << endl;
    return 0;
}