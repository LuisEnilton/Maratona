//
// Created by Luis on 18/11/2023.
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
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

bool check(vi &freq) {
    if (freq[0] == 0 || freq[1] == 0 || freq[2] == 0) return false;
    return freq[0] > 1 || freq[1] > 1 || freq[2] > 1;
}

void solve() {
    string s; cin >> s;
    int n = s.size();
    vi freq(3);
    int ans = INF;
    for (int r = 0, l = 0; r < n; r++) {
        freq[s[r] - '1']++;
        while (check(freq) && l < r) {
            if (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                ans = min(ans, (r - l) + 1);
            }
            freq[s[l] - '1']--;
            l++;

        }
        if (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
            ans = min(ans, (r - l) + 1);
        }
    }
    cout << (ans == INF ? 0 : ans) << endl;
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

