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

int bit[MAXN];
int arr[MAXN];

void upd(int x, ll v){
    while(x < MAXN){
        bit[x] += v;
        x += (x & -x);
    }
}

ll qry(int x){
    ll ret = 0;

    while(x > 0){
        ret += bit[x];
        x -= (x & -x);
    }
    return ret;
}

map<int,ll> mapa;
void compressor(vector<int>& a){
    int n = a.size();
    vector<pair<int, int>> pairs(n);
    for(int i = 0; i < n; ++i) {
        pairs[i] = {a[i], i};
    }
    sort(pairs.begin(), pairs.end());
    int nxt = 1;
    for(int i = 0; i < n; ++i) {
        if(i > 0 && pairs[i-1].first != pairs[i].first) nxt++;
        a[pairs[i].second] = nxt;
        mapa[pairs[i].first] = nxt;
    }
}


int main() {
    //optimize;
    int n;
    cin >> n;
    vector<rng> v(n), v2(n);
    vi ans(n);
    ordered_set aux;
    vi a;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.PB(x);
        a.PB(y);
        v[i] = {{x,-y},i};
        v2[i] = {{y, -x },i};
    }
    for(auto x : a){
        cout << x << " ";
    }
    cout << endl;
    UNIQUE(a);
    for(auto x : a){
        cout << x << " ";
    }
    cout << endl;
    compressor(a);
    for(auto x : a){
        cout << x << " ";
    }
    cout << endl;
    sort(ALL(v));
    sort(ALL(v2));
    

    for(auto &[pa , id] : v){
        auto &[x,y] = pa;
        y = -y;
        //cout << x << " " << mapa[x] << endl;
        //cout << y << " " << mapa[y] << endl;
        x = mapa[x];
        y = mapa[y];

    }

    for(auto &[pa , id] : v2){
        auto &[x,y] = pa;
        y = -y;
        //cout << x << " " << mapa[x] << endl;
        //cout << y << " " << mapa[y] << endl;
        x = mapa[x];
        y = mapa[y];

    }
    //for(auto x : v){    cout << x.first.first << " " << x.first.second << endl;}
    for(int i = n-1;i>=0;i--){
        auto [x,id] = v[i];
        auto [start,end] = x;
        end = end;

        auto q  = qry(end );
        ans[id] = q;

        upd(end,1);
    }



    for(int i = 0; i < n;i++){
        cout << ans[i] << " ";
    }
    aux.clear();
    cout << endl;
    fill(bit,bit + MAXN,0);
    for(int i = n-1; i >=0;i--){
        auto [x,id] = v2[i];
        auto [end,start] = x;
        start = start;

        auto q = qry(start );
        ans[id] = q;

        upd(start,1);
    }

    for(int i = 0; i < n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

