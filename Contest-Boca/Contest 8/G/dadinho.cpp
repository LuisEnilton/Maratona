//
// Created by Luis on 18/07/2023.
//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
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
#define MAXN 505
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

int N, M, X, Y, E;

ll mapa[MAXN][MAXN];
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int custo[] = {7, 6, 5, 8, 4, 1, 2, 3};

vector<vector<ll>> Dijkstra(int X, int Y)
{
    vector<vector<ll>> dist(N + 1, vector<ll>(M + 1, INFLL));

    priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> pq;

    pq.push({0, {X, Y}});
    dist[X][Y] = 0;

    while (!pq.empty())
    {
        auto [x, y] = pq.top().second;
        pq.pop();

        if (x < 1 || x > N || y < 1 || y > M) continue;
        if (mapa[x][y] != 0) continue;

        mapa[x][y] = -1;

        for (int i = 0; i < 8; i++)
        {
            int _x = x + dx[i];
            int _y = y + dy[i];

            if (_x < 1 || _x > N || _y < 1 || _y > M) continue;

            if (dist[_x][_y] > dist[x][y] + custo[i])
            {
                dist[_x][_y] = dist[x][y] + custo[i];
                pq.push({dist[_x][_y], {_x, _y}});
            }
        }
    }

    return dist;
}

int main(int argc, char** argv)
{
    optimize;

    cin >> N >> M >> X >> Y >> E;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            cin >> mapa[i][j];
        }

    auto dist = Dijkstra(X, Y);

    ll ans = 0;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            // cerr << dist[i][j] << " \n"[j == M];
            if (dist[i][j] <= E)
                ans = max(ans, mapa[i][j]);
        }


    cout << ans << endl;

    return 0;
}