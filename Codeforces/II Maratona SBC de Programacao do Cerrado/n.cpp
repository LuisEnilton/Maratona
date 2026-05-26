//
// Created by Luis on 06/09/2023.
//
// Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define BT bitset<500>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define MAXN 1000010
#define int ll
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>


void solve()
{
    string fin; cin >> fin;
    string ini; cin >> ini;

    int h1 = (ini[0] - '0') * 10 + ini[1];
    int h2 = (fin[0] - '0') * 10 + fin[1];
    int m1 = (ini[3] - '0') * 10 + ini[4];
    int m2 = (fin[3] - '0') * 10 + fin[4];

    int diff = (h2 - h1);
    int diffm = (m2 - m1);
    if(m2 < m1) {
        diff--;
        diffm = (m2 + 60) - m1;
    }


    if(diff < 10) cout << 0;
    cout << diff << ":";
    if(diffm < 10) cout << 0;
    cout << diffm << endl;
}


signed main()
{
    optimize;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
