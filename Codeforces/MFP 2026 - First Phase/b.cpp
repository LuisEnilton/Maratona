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
    string sa, sp;
    cin >> sa >> sp;
    int sza = sa.size(), szp = sp.size();

    map<char, int> cnta, cntp;
    for (auto c : sa)
        cnta[c]++;
    for (auto c : sp)
        cntp[c]++;
    int q;
    cin >> q;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int k;
            cin >> k;
            string s;
            cin >> s;
            for (auto c : s)
            {
                cnta[c] += k;
                sza += k;
            }
        }
        if (op == 2)
        {
            int k;
            cin >> k;
            string s;
            cin >> s;
            for (auto c : s)
            {
                cntp[c] += k;
                szp += k;
            }
        }
        if (op == 3)
        {
            int curra = sza, currp = szp;
            bool emp = 1;
            for (char c = 'a'; c <= 'z'; c++)
            {
                curra -= cnta[c], currp -= cntp[c];
                if (cnta[c] < cntp[c])
                {
                    cout << (curra == 0 ? "ADA" : "PY") << endl;
                    emp = 0;
                    break;
                }
                else if (cntp[c] < cnta[c])
                {
                    cout << (currp > 0 ? "ADA" : "PY") << endl;
                    emp = 0;
                    break;
                }
            }
            if (emp)
                cout << "EMPATE" << endl;
        }
    }
    return 0;
}
