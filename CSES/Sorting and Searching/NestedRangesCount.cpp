//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cmath>

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
#define vb vector<bool>
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
typedef pair<pii, int> rng;


int main() {
    optimize;
    int n;
    cin >> n;
    vector<rng> v(n), v2(n);
    vi ans(n);
    ordered_set aux;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[i] = {{x,-y},i};
        v2[i] = {{y, -x },i};
    }
    sort(ALL(v));
    sort(ALL(v2));

    for(int i = n-1;i>=0;i--){
        auto [x,id] = v[i];
        auto [start,end] = x;
        end = -end;

        auto q = aux.order_of_key(end + 1);
        ans[id] = q;

        aux.insert(end);
    }

    for(int i = 0; i < n;i++){
        cout << ans[i] << " ";
    }
    aux.clear();
    cout << endl;

    for(int i = n-1; i >=0;i--){
        auto [x,id] = v2[i];
        auto [end,start] = x;
        start = -start;

        auto q = aux.order_of_key(start + 1);
        ans[id] = q;

        aux.insert(start);
    }

    for(int i = 0; i < n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

