//
// Created by Luis on 01/08/2023.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/random>
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
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

const int MAXN = 1e6 + 5;

struct BIT2D {
    ll bit[MAXN][MAXN];

    void update(int X, int Y, int val)
    {
        for(int x = X; x < MAXN; x += x&(-x))
            for(int y = Y; y < MAXN; y += y&(-y))
                bit[x][y] += val;
    }

    int query(int X, int Y)
    {
        int sum = 0;

        for(int x = X; x > 0; x -= x&(-x))
            for(int y = Y; y > 0; y -= y&(-y))
                sum += bit[x][y];

        return sum;
    }

    int queryArea(int xi, int yi, int xf, int yf){
        return query(xf, yf) - query(xf, yi-1) - query(xi-1, yf) + query(xi-1, yi-1);
    }

    void init(){
        memset(bit, 0, sizeof bit);
    }

} Bit;
int n , m ,q;

__gnu_cxx::sfmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b){return uniform_int_distribution<ll>(a, b)(rng);}


int main(int argc, char** argv)
{
    optimize;
    cin >> n >> m >> q;
    BIT2D bit = *new BIT2D();
    bit.init();
    while(q--){
        int op; cin >> op;
        if(op == 1){ // colocar barreira
            int r1,c1,r2,c2;
            cin >> r1 >> c1 >> r2 >> c2;
            ll rnd = randint(1 , 10e9+7);
          bit.update();
        }
    }
    return 0;
}