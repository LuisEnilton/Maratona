// Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 1000000010
#define INFLL 1000000000000000010LL
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
#define MAXN 501
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1}; // mexe na altura
int dx[] = {-1, 0, 1, 1, -1, -1, 0, 1}; // mexe na largura
int N, M, pi, pf, ep;


bool check(int x, int y)
{
    if (x < 0 || x >= N || y < 0 || y >= M)
    {
        return false;
    }
    return true;
}

int maior = 0;
int salas[MAXN][MAXN];

void solve(int l, int c,int ep)
{
    ep -= l + c + 2;
    if(ep < 0) return;
    if (salas[l][c] == -1)
        return;

    if (salas[l][c] != 0 )
    {

        if (salas[l][c] > maior )
        {
            maior = salas[l][c];
        }
        salas[l][c] = -1;
        return;
    }
    salas[l][c] = -1;
    for (int i = 0; i < 8; i++)
    {
        int yy = l + dy[i];
        int xx = c + dx[i];

        if (check(yy, xx))
            solve(yy, xx,ep);
    }
    return;
}

int n;
int main(int argc, char **argv)
{
    optimize;
    cin >> N >> M >> pi >> pf >> ep;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            cin >> salas[i][j];
        }
    }
    ep += pi+pf;
    solve(pi-1, pf-1,ep);
    cout << maior << endl;

    return 0;
}