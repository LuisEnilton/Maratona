//
// Created by luise on 27/08/2023.
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
#define y first
#define x second
#define a_num first.first
#define a_den first.second
#define b second
#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>
typedef pair<int,int> Point;


int is_left(Point a, Point b, Point c) {
    int det = (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
    if (det > 0) return 1;  // c esta a esquerda
    if (det < 0) return -1; // c esta a direita
    return 0;               // c é colinear
}

int main(int argc, char** argv)
{
    optimize;
    int n,xa,xb;
    cin >> n >> xa >> xb;
    Point pt[n];
    for(int i =0; i < n;i++){
        cin >> pt[i].x;
        cin >> pt[i].y;
    }

    sort(pt,pt+n);
    Point pa = Point(0,xa);
    Point pb = Point(0,xb);

    int memo[n],ans = 0;

    for(int i =0 ; i < n;i++){
        memo[i] = 1;
    }

    for(int i =0; i < n;i++){
        memo[i] = 1;
        for(int j =i-1;j >= 0 ;j--){
            if(is_left(pt[i],pa,pt[j]) == 1 && is_left(pb,pt[i],pt[j]) == 1 ){
                memo[i] = max(memo[i],memo[j] + 1);
            }
        }
        ans = max(ans ,memo[i]);
    }
    cout << ans << endl;

    return 0;
}

