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

int capacidade,n;

int peso[MAXN], valor[MAXN];

int dp[MAXN][MAXN];

int solve(int i, int pesoAtual){
    if(i == n)
        return 0;
    
    if(pesoAtual + peso[i] > capacidade)
        return solve(i+1, pesoAtual);
    if(dp[i][pesoAtual] != -1)
        return dp[i][pesoAtual];
    dp[i][pesoAtual] = max(solve(i+1, pesoAtual), solve(i+1, pesoAtual + peso[i]) + valor[i]);
    return dp[i][pesoAtual];
}



int main()
{
    cin >> capacidade >> n;
    memset(dp, -1, sizeof dp);
    for (size_t i = 0; i < n; i++)
    {
        cin >> peso[i] >> valor[i];
    }
    
    cout<<solve(0,0)<<endl;

}
