//
// Created by Luis on 15/08/2023.
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

int N, X;

struct Ponto
{
    ll x, y, val, pos, id;

    Ponto(ll _x = 0, ll _y = 0, ll _val = 0, ll _pos = 0, ll _id = 0) : x(_x), y(_y), val(_val), pos(_pos), id(_id) {}

    //Produto cruzado de dois vetores
    //(0, 0) => (x, y)
    bool operator<(const Ponto &a) const
    {
        return x * a.y > y * a.x;
    }
};

ll ans[MAXN];

ll bit[MAXN];

void add(int x, ll v)
{
    for (; x < MAXN; x += (x & -x))
        bit[x] += v;
}

ll query(int x)
{
    ll ret = 0;

    for (; x > 0; x -= (x & -x))
        ret += bit[x];

    return ret;
}

void solve(vector<Ponto> &pontos)
{
    int N = pontos.size();

    memset(bit, 0, sizeof bit);

    sort(ALL(pontos));

    for (int i = 0; i < N; i++)
    {
        pontos[i].pos = i + 1;
    }

    for (int i = 0; i < N; i++)
    {
        pontos[i].x -= X;
    }

    sort(ALL(pontos));
    reverse(ALL(pontos));

    for (int i = 0; i < N; i++)
    {
        auto id = pontos[i].id;
        auto p = pontos[i].pos;

        ans[id] = query(p - 1);

        add(p, pontos[i].val);
    }
}

int main(int argc, char** argv)
{
    optimize;

    cin >> N >> X;

    vector<Ponto> cima, baixo;

    for(int i = 0, x, y, v; i < N; i++)
    {
        cin >> x >> y >> v;

        cima.EB(x, y, v, i, i);
    }

    solve(cima);

    for (int i = 0; i < N; i++)
        cout << ans[i] << endl;

    return 0;
}