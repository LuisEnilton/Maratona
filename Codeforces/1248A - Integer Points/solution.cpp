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
#define a_num first.first
#define a_den first.second
#define b second
typedef pair<double,double> Point;
typedef pair<pair<ll,ll>,ll> Line;

Point intersection_point(Line a, Line b){
    double det = double(a.first.first*b.first.second) - double(b.first.first*a.first.second);
    double g = double(b.first.second*a.second - a.first.second*b.second)/det;
    double h = double (a.first.first*b.second - b.first.first*a.second)/det;
    return {g,h};
}

bool check(Point &p){
    double r1 = round(p.x);
    double r2 = round(p.y);
    if(abs(p.x - r1) <=EPS && abs(p.y - r2) <=EPS){
        return true;
    }
    return false;
}


int main(int argc, char** argv)
{
    optimize;
    int t; cin >> t;
    while(t--){
        vector<pair<ll,ll>> parity(2,{0,0});
        int n; cin >> n;
        for(int i =0;i < n;i++){
            ll b;
            cin >> b;
            if(b & 1){
                parity[0].second++;
            }else{
                parity[0].first++;
            }
        }
        int m; cin >> m;

        for(int i =0;i < m;i++){
            ll b;
            cin >> b;
            if(b & 1){
                parity[1].second++;
            }else{
                parity[1].first++;
            }
        }
        ll ans = parity[0].first * parity[1].first + parity[0].second*parity[1].second;
        cout << ans << endl;
    }
    return 0;
}

