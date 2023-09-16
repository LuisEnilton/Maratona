//
// Created by Luis on 16/09/2023.
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
int results[10];
int m;
vector<string> reels(3);


int solve(vi ordem, int num) {
    int ans = 0;
    vector<bool> visitado(3*m);
    for (int i = 0; i < 3; i++) {
        string s = reels[ordem[i]];
        int pos = 301;
        for (int j = 0; j < 3 * m; j++) {
            if (s[j % m] - '0' == num && !visitado[j]) {
                pos = j;
                visitado[j] = true;
                break;
            }

        }
        ans = max(pos,ans);
    }

    return ans;
}


int main(int argc, char **argv) {
    optimize;
    cin >> m;
    for (auto &s: reels) cin >> s;
    vi nums = {0, 1, 2};
    int ans = INF;
    do {
        for (int i = 0; i < 10; i++) {

           ans = min(ans, solve(nums, i));
        }

    } while (next_permutation(ALL(nums)));
    if(ans == 301){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

    return 0;
}

