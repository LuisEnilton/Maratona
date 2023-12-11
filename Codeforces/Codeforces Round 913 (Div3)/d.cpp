//
// Created by luise on 11/12/2023.
//
//
// Created by luise on 11/12/2023.
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
#define l first
#define r second
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

bool check(int k, vii &segments) {
    int maxi = 0, mini = 0;
    // pra cada segmento guarda o menor que é possivel chegar e o maior
    for (auto [esq, dir]: segments) {
        maxi = min(maxi + k, dir);
        if (maxi < esq) return false;
        mini = max(mini - k, esq);
        if (mini > dir) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vii segments(n);
    int maxi = 0;
    for (auto &x: segments) {
        cin >> x.l;
        cin >> x.r;
        maxi = max(maxi, x.r);
    }

    int le = 0, ri = maxi;
    int ans = ri;
    while (le <= ri) {
        int mid = (le + ri) / 2;
        if (check(mid, segments)) {
            ans = mid;
            ri--;
        } else {
            le++;
        }
    }
    cout << ans << endl;
}

int main() {
    optimize;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

