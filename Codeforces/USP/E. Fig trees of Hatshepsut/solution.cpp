//
// Created by luise on 09/08/2023.
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
//#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>
vi phi;
vi phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi;
}

const int MAXN = 2e5 + 5;
int seg[4*MAXN];
int lazy[4*MAXN];

void unlazy(int no, int l, int r){
    if(lazy[no] == 0) return;

    int m=(l+r)>>1, e=no*2, d=no*2+1;

    seg[no] += (r-l+1) * lazy[no];

    if(l != r){
        lazy[e] += lazy[no];
        lazy[d] += lazy[no];
    }

    lazy[no] = 0;
}

int query(int no, int l, int r, int a, int b){
    unlazy(no, l, r);
    if(b <  l || r <  a) return 0;
    if(a <= l && r <= b) return seg[no];

    int m=(l+r)>>1, e=no*2, d=no*2+1;

    return query(e, l, m, a, b) + query(d, m+1, r, a, b);
}

void update(int no, int l, int r, int a, int b, int v){
    unlazy(no, l, r);
    if(b <  l || r <  a) return;
    if(a <= l && r <= b)
    {
        lazy[no] += v;
        unlazy(no, l, r);
        return;
    }

    int m=(l+r)>>1, e=no*2, d=no*2+1;

    update(e, l,   m, a, b, v);
    update(d, m+1, r, a, b, v);

    seg[no] = seg[e] + seg[d];
}


void build(int no, int l, int r, vector<int> &lista){
    if(l == r){ seg[no] = lista[l-1]; return; }

    int m=(l+r)>>1, e=no*2, d=no*2+1;

    build(e, l,   m, lista);
    build(d, m+1, r, lista);

    seg[no] = seg[e] + seg[d];
}

int main(int argc, char** argv)
{
    //optimize;
    int n,q;
    cin >> n >> q;
    vi nums(n,0);
    int maior = 0 ;
    for(auto &x:nums){
        cin >> x;
        maior = max(maior,x);
    }

    phi = phi_1_to_n(maior);

    for(auto x : phi) cerr << x << " ";
    build(1,1,n,nums);

    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int l ,r;
            cin >> l >> r;
        }
        if(op == 2){
            int l ,r , x;
        }
    }
    return 0;
}

