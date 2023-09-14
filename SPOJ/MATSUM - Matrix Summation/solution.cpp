//
// Created by Luis on 09/09/2023.
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
#define MAXN 1030
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>
struct BIT2D {
    int bit[MAXN][MAXN];

    void update(int X, int Y, int val){
        for(int x = X; x < MAXN; x += x&(-x))
            for(int y = Y; y < MAXN; y += y&(-y))
                bit[x][y] += val;
    }

    int query(int X, int Y){
        int sum = 0;

        for(int x = X; x > 0; x -= x&(-x))
            for(int y = Y; y > 0; y -= y&(-y))
                sum += bit[x][y];

        return sum;
    }

    void updateArea(int xi, int yi, int xf, int yf, int val){
        update(xi,   yi,    val);
        update(xf+1, yi,   -val);
        update(xi,   yf+1, -val);
        update(xf+1, yf+1,  val);
    }

    int queryArea(int xi, int yi, int xf, int yf){
        return query(xf, yf) - query(xf, yi-1) - query(xi-1, yf) + query(xi-1, yi-1);
    }

    void init(){
        memset(bit, 0, sizeof bit);
    }

} Bit;


int main(int argc, char** argv)
{
    while(true){
        int op; cin >> op;
        if(op == 1){
            int x,y,val; cin >> x>>y >> val;
            Bit.update(x,y,val);
        }else{
            int x,y; cin >> x >> y;
            cout << Bit.query(x,y) << endl;
        }
    }
    return 0;
}

