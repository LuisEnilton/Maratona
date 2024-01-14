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
    int l = 0; // quem pode doar
    for(int r = 1; r < n;r++){
        double giv = acc[l] - energy;
        double rcv = energy - acc[r];
        double val = min(giv,rcv);
    }
}


int main() {
    optimize;
    cin >> n >> k;
    acc.resize(n);
    for (auto &x: acc) cin >> x;
    sort(ALL(acc));
    double ans = 0;
    double l = 0, r = acc[n - 1];
    while (abs(l - r) < EPS) {
        double m = (l + r) / 2;
        if (check(m)) {
            ans = m;
            l++;
        } else {
            r--;
        }
    }
    return 0;
}

