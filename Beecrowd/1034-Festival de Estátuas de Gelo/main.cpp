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

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;

int T;
vi blocos;
int qtd;
int M;
int dp[MAXN];


int solve(int m) {
    if (m == 0) {
        return 0;
    }

    if(m<0 ) return INF;


    if (-1 != dp[m]) {
        return dp[m];
    }
    int ans = INF;
    for (auto &x: blocos) {
        ans = min(ans, solve(m - x) + 1);
    }


    return dp[m] = ans;
}


int main() {
    optimize;
    cin >> T;
    while (T--) {
        cin >> qtd >> M;
        blocos.resize(qtd);

        for (auto &x: blocos) {
            cin >> x;
        }

        for (int i = 0; i <= M; i++) {
            dp[i] = -1;
        }

        for (int i = 0; i <= M; i++) {
            solve(i);
        }
        cout << solve(M) << endl;

    }


}
//
// Created by Luis on 24/06/2023.
//
