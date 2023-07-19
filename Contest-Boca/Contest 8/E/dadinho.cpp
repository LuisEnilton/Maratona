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
#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

int N, S;

int sum[220][220];

int get(int x1, int y1, int x2, int y2)
{
    return sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
}

int main(int argc, char** argv)
{
    optimize;

    cin >> S >> N;

    for (int i = 0, x, y; i < N; i++)
    {
        cin >> x >> y;

        sum[x][y]++;
    }

    for (int i = 1; i <= 210; i++)
        for (int j = 1; j <= 210; j++)
            sum[i][j] += sum[i - 1][j] + sum[i][j-1] - sum[i-1][j-1];


    int ans = 0;

    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= 100; j++)
            ans = max(ans, get(i, j, i + S, j + S));


    cout << ans << endl;

    return 0;
}