//
// Created by Luis on 26/07/2023.
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
#define MAXN 100010
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

int n,t,q;

int ps[MAXN];

int main(int argc, char** argv)
{
    optimize;
    cin >> t;
    for(int i =1;i<=t;i++){
        cin >> n >> q;
        ll anterior = 0;
        for (int j = 0; j < n; j++) {
            ll v;
            cin >> v;
            if(j >0){
                if( v > anterior)
                    ps[j] = ps[j - 1] + 1;
                else
                    ps[j] = ps[j-1];
            }else{
                ps[j] = 1;
            }

            anterior = v;
        }
        cout <<"Case " << i << ":" << endl;
        while(q--){
            int l,r;
            cin >> l >> r;
            cout << ps[r - 1] - ps[l - 1] + 1 << endl;
        }
    }

    return 0;
}