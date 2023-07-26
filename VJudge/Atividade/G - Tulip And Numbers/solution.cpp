// Created by Luis on 24/07/2023.
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
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>



int n,q;
const int MAXN = 10e5+10;
ll BIT[MAXN];
void update( ll x, int v){
    for(; x <= n; x += x&-x) BIT[x] += v;
}

ll query( int x){
    if(x == 0) return 0;
    ll sum = 0;
    for(; x > 0; x -= x&-x) sum += BIT[x];
    return sum;
}


void converter(vector<ll> &v){
    //compressão de coordenadas
    vector<ll> temp(n);

    for(int i = 0; i < n; i++) temp[i] = v[i];
    sort(ALL(temp));

    for(int i = 0; i < n; i++) v[i] = POS(temp, v[i]) + 1;
}


void count(vector<ll> &v) {

    converter(v);




    for(int i = 0; i <= n; i++) BIT[i] = 0;
    ll valAtual =0;
    for(int i = 0; i < n; i++){
        if(i >= 1){
            if(v[i] != v[i-1])
                update( v[i], 1);

        }
        else
            update(v[i],1);


    }




}

vector<ll> nums;
int main(int argc, char **argv) {
    optimize;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin.ignore();
        cin >> n >> q;

        nums.resize(n);
        for(auto &x:nums) cin >> x;
        count(nums);
        cout << "Case " << i <<":" << endl;
        while(q--){
            int l ,r;
            cin >> l >> r;
            cout << query(r) - query(l-1)  << endl;
        }
    }
    return 0;
}