#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
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
#define MAXN 200010
#define MAXL 32
#define EPS 1e-9
#define endl '\n'

using namespace std;

int n, q, ancestral[MAXN][MAXL];

void precalc()
{
    for (int j = 1; j < MAXL; j++)
        for (int i = 1; i <= n; i++)
            if(ancestral[i][j - 1] != -1)
                ancestral[i][j] = ancestral[ancestral[i][j - 1]][j - 1];
}


// O(MAXL)
int kth_ancestor(int u, int k)
{
    for (int i = MAXL - 1; i >= 0; i--)
        if (k & (1 << i) && u != -1)
            u = ancestral[u][i];

    return u;
}

int main(int argc, char** argv)
{
    optimize;

    memset(ancestral, -1, sizeof ancestral);

    cin >> n >> q;

    for (int i = 1, u; i <= n; i++)
    {
        cin >> u;

        ancestral[i][0] = u;
    }

    precalc();

    while (q--)
    {
        int u, k;
        cin >> u >> k;

        auto ans = kth_ancestor(u, k);

        cout << ans << endl;
    }

    return 0;
}