//
// Created by luise on 28/08/2023.
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
#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>
#define x first
#define y second
typedef pair<int, int> Point;
typedef pair<Point, int> Circle;

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int r, d;

int main(int argc, char **argv) {
    optimize;
    cin >> r >> d;
    int n;
    cin >> n;
    vector<Circle> circles(n);
    Point ori = {0, 0};
    for (auto &c: circles) {
        cin >> c.first.x;
        cin >> c.first.y;
        cin >> c.second; // raio
    }

    int ans = 0;
    for (auto c: circles) {
        double dist = distance(ori, c.first);//distancia entre os centros
        double mainR = double(r - d) + double(c.second);
        double dBorda = dist + (double)c.second;
        if ((dist - mainR) >= -1 * EPS  ) {
            if((dBorda - (double) r ) <= EPS){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

