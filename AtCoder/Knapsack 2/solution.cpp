//
// Created by Luis on 22/07/2023.
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
//#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

int n,w;
vector<ll> weights;
vi values;
const int MAXN = 10e5+1;
int dp[100][MAXN];

int solve(int i ,ll sack){
    if(sack > w)
        return -1 * INF;
    if(i >= n)
        return 0;

    if(dp[i][sack] != -1 ) return dp[i][sack];

    int pega = values[i] + solve(i+1,sack + weights[i]);
    int n_pega = 0 + solve(i+1,sack);

    return dp[i][sack] = max(pega,n_pega);
}

int main(int argc, char** argv)
{
    optimize;
    cin >> n >> w;
    weights.resize(n);
    values.resize(n);
    for (int i = 0; i < n; i++) {
        ll wei ;
        int v;
        cin >> wei >> v;
        weights[i] = wei;
        values[i] = v;
    }

    cout <<solve(0,0) << endl;
    return 0;
}