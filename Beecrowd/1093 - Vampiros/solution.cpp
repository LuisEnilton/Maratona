//
// Created by Luis on 06/10/2023.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 1000000010
#define INFLL 1000000000000000010LL
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
#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>


int main() {
    while (true) {
        int EV1, EV2, AT, D;
        cin >> EV1 >> EV2 >> AT >> D;

        if (EV1 == 0 && EV2 == 0 && AT == 0 && D == 0) {
            break;
        }

        EV1 = ceil(static_cast<double>(EV1) / D);
        EV2 = ceil(static_cast<double>(EV2) / D);
        int n = EV1 + EV2;
        double x, y;

        if (AT == 3) {
            x = static_cast<double>(EV1);
            y = static_cast<double>(n);
        } else {
            x = 1 - pow((6 - AT) / static_cast<double>(AT), EV1);
            y = 1 - pow((6 - AT) / static_cast<double>(AT), n);
        }

        double resposta = round(100 * x / y * 10) / 10; // Round to 1 decimal place
        cout << fixed; // Ensure decimal point is printed
        cout <<  setprecision(1)<< resposta << endl;
    }

    return 0;
}

