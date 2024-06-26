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

int n,q;

void update(ll BIT[], int x, int v){
    for(; x <= n; x += x&-x) BIT[x] += v;
}

ll query(ll BIT[], int x){
    ll sum = 0;
    for(; x > 0; x -= x&-x) sum += BIT[x];
    return sum;
}


void convert(vector<ll> &v){
    //compressão de coordenadas
    vector<ll> temp(n);

    for(int i = 0; i < n; i++) temp[i] = v[i];
    sort(ALL(temp));

    for(int i = 0; i < n; i++) v[i] = POS(temp, v[i]) + 1;
}


ll inversion_count(vector<ll> &v) {

    ll inv = 0;
    convert(v);

    n = v.size();
    ll BIT[n+1]; // 1 indexado

    for(int i = 0; i <= 3; i++) BIT[i] = 0;

    for(int i = n-1; i >= 0; i--){
        inv += query(BIT, v[i]-1);
        update(BIT, v[i], 1);
    }

    return inv;

}




int main() {
    optimize;
    string s; cin >> s;
    vector<ll> v;
    for(auto c : s){
        v.push_back(int(c) - '0' + 1);
    }
    cout << inversion_count(v) << endl;
    return 0;
}

/*
 * 221100
 *
 *
 * */