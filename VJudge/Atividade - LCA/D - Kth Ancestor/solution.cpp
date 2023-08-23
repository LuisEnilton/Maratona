//
// Created by Luis on 22/08/2023.
//
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
#define MAXL 25
#define EPS 1e-9
#define endl '\n'

using namespace std;

int N, Q, ancestral[MAXN][MAXL];

void precalc()
{
    for (int j = 1; j < MAXL; j++)
        for (int i = 1; i < MAXN; i++)
            if(ancestral[i][j - 1] != -1)
                ancestral[i][j] = ancestral[ancestral[i][j - 1]][j - 1];
}

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

    int T;

    cin >> T;

    while(T--)
    {
        memset(ancestral, -1, sizeof ancestral);

        cin >> N;

        for (int i = 1, u, v; i <= N; i++)
        {
            cin >> u >> v;

            if (v == 0) v = -1;

            ancestral[u][0] = v;
        }

        precalc();

        cin >> Q;

        while (Q--)
        {
            int op, X, Y, K;

            cin >> op;

            if (op == 0)
            {
                cin >> Y >> X;

                ancestral[X][0] = Y;

                for (int i = 1; i < MAXL; i++)
                    if (ancestral[X][i - 1] != -1)
                        ancestral[X][i] = ancestral[ancestral[X][i - 1]][i - 1];
            }
            else if (op == 1)
            {
                cin >> X;

                for (int i = 0; i < MAXL; i++)
                    ancestral[X][i] = -1;
            }
            else
            {
                cin >> X >> K;

                cout << max(0, kth_ancestor(X, K)) << endl;
            }
        }
    }

    return 0;
}