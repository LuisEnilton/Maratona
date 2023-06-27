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
#define MAXN 101010
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;

int N;
vi seq;

map<pii, int> dp;

int solve(int i, int ultimo)
{
    if (i == N)
        return 0;
    if( dp[{i,ultimo}] != 0)
        return dp[{i,ultimo}];
    
    if (seq[i] < ultimo)
        return  dp[{i,ultimo}] =   solve(i + 1, ultimo);

    return dp[{i,ultimo}] = max(solve(i+1, ultimo), solve(i + 1, seq[i]) + 1);
}

int main()
{
    cin >> N;
    seq.resize(N);
    for (size_t i = 0; i < N; i++)
        cin >> seq[i];
    int ans = solve(0, 0);
    cout << ans << endl;
}
