//
// Created by Luis on 06/09/2023.
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


int main(int argc, char **argv) {
    //optimize;
    freopen("shell.in", "r", stdin);
    int n;
    cin >> n;
    vector<bool> shell(3, false);
    vii swaps(n);
    vi guess(n);
    for (int i = 0; i < n; i++) {
        cin >> swaps[i].first;
        swaps[i].first--;
        cin >> swaps[i].second;
        swaps[i].second--;
        cin >> guess[i];
        guess[i]--;
    }
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        for(int k = 0;k < 3;k++) shell[i] = false;
        shell[i] = true;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            swap(shell[swaps[i].first], shell[swaps[i].second]);
            cnt += shell[guess[i]];
        }
        ans = max(ans, cnt);
    }
    freopen("shell.out", "w", stdout);
    cout << ans << endl;
    return 0;
}

