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

int N, M;
vi A, B;
int dp[1000][1000];

int lcs(int i, int j)
{
    if (i == N || j == M)
        return 0;

    if (A[i] == B[j]){
        if (dp[i][j] != -1)
            return dp[i][j];
        
        return dp[i][j] = 1 + lcs(i + 1, j + 1);
    }

    if (dp[i][j] != -1)
        return dp[i][j];
    
    return dp[i][j] = max(lcs(i + 1, j), lcs(i, j + 1));
}
/*  abc  bc    c    0
    bcd  bcd   cd   d ret 2
         abc   bc   c
         cd    cd   cd
                    bc
                    d
               abc  bc
               d    d
                    bc
                    0
*/
int main()
{
    cin >> N >> M;
    A.resize(N);
    B.resize(M);
    memset(dp, -1, sizeof dp);
    for (int &x : A)
        cin >> x;
    for (int &x : B)
        cin >> x;
    int ans = lcs(0, 0);
    cout << N - ans << " " << M - ans << endl;
}
