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



int n;
vi nums;
const int MAXN = 3*10e4 + 10;
bitset<3000> seg[4 * MAXN];

bitset<3000> query(int no, int l, int r, int a, int b)
{
    if (b < l || r < a)
        return 0;
    if (a <= l && r <= b)
        return seg[no];

    int m = (l + r) / 2, e = no * 2, d = no * 2 + 1;

    return query(e, l, m, a, b) | query(d, m + 1, r, a, b);
}

void update(int no, int l, int r, int pos, ll v)
{
    if (pos < l || r < pos)
        return;
    if (l == r)
    {
        seg[no].set(v - 1);
        return;
    }

    int m = (l + r) / 2, e = no * 2, d = no * 2 + 1;

    update(e, l, m, pos, v);
    update(d, m + 1, r, pos, v);

    seg[no] = seg[e] | seg[d];
}

void build(int no , int l ,int r){
    if(l == r){
        seg[no].set(nums[l] - 1);
        return;
    }
    int m = (l+r)/2, e = no*2, d = no*2+1;
    build(e,l,m);
    build(d,m+1,r);
    seg[no] = seg[e] | seg[d];
}


//algoritmo de compressão de coordenadas dado um vector<int>
//retorna um vector<int> com as coordenadas comprimidas
//complexidade O(nlogn)
vi compress(vi &v){
    vi ret = v;
    ret;
    for(auto &x : v){
        x = POS(ret,x);
    }
    return ret;
}



int q;
int main(int argc, char **argv) {


        cin >> n ;
        vi aux(n);

        for(int i = 0;i < n;i++){
            cin >> aux[i];
        }
        nums = compress(aux);
        build(1,0,n-1);
        cin >> q;
        while(q--){
            int l ,r;
            cin >> l >> r;
            l--,r--;
            cout <<  query(1,0,n-1,l,r).count() << endl;
        }

    return 0;
}