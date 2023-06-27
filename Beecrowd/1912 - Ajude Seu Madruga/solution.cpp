#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <string>
#include <algorithm>
#include <set>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 100000010
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
#define MAXN 1010010
#define MAXL 23
#define endl '\n'
#define EPS 0.000000001
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;

int N = 1, A = 1;
vi tiras;

ld calcula_area(ld altura_corte) {
    ld area = 0;
    for (auto tira: tiras) {
        if (tira > altura_corte) {
            area += tira - altura_corte;
        }
    }

    return area;
}


int main() {
    optimize;
    while ((cin >> N >> A) && (N != 0 || A != 0)) {
        tiras.resize(N);
        ll soma = 0;
        for (auto &tira: tiras) {
            cin >> tira;
            soma += tira;
        }

        if (soma < A) {
            cout << "-.-" << endl;
            continue;
        }
        if (soma == A) {
            cout << ":D" << endl;
            continue;
        }

        sort(ALL(tiras));
        ld l = 0, r = tiras[N - 1], m;
        while ((abs(r - l) > EPS)) {
            m = (l + r) / 2.0;
            ld area = calcula_area(m);

            if (area >= A) {
                l = m;
            } else {
                r = m;
            }

        }
        cout << setprecision(4) << fixed << m << endl;
    }

}



//
// Created by Luis on 24/06/2023.
//
