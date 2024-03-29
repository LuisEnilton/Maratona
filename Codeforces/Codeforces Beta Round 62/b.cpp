//
// Created by Luis on 14/12/2023.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cmath>

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
#define EPS 1e-6
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

int n, k;
vector<double> acc;

bool check(double energy) {
    double giving = 0, receving = 0;
    for (int r = 0; r < n; r++) {
        if (acc[r] > energy) {
            giving += abs(acc[r] - energy);
        } else {
            receving += abs(acc[r] - energy);
        }
    }
    return giving * ( (double) (100-k) /  100) >= receving;
}


int main() {
    optimize;
    cin >> n >> k;
    acc.resize(n);
    for (auto &x: acc) cin >> x;
    sort(ALL(acc));
    double ans = 0;
    double l = 0.0, r = 10e9;
    while (abs(l - r) > EPS) {
        double m = (l + r) / 2.0;
        if (check(m)) {
            ans = m;
            l = m ;
        } else {
            r = m;
        }
    }

    cout << setprecision(9)  << fixed << ans << endl;
    return 0;
}

