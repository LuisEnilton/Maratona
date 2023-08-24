//
// Created by Luis on 09/08/2023.
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

const int MAXN = 1e6 + 5;
int seg[4 * MAXN];


int query(int no, int l, int r, int a, int b) {
    if (b < l || r < a) return 1;
    if (a <= l && r <= b) return seg[no];

    int m = (l + r) / 2, e = no * 2, d = no * 2 + 1;
    return query(e, l, m, a, b) * query(d, m + 1, r, a, b);
}

void update(int no, int l, int r, int pos, int v) {
    if (pos < l || r < pos) return;
    if (l == r) {
        seg[no] = v;
        return;
    }

    int m = (l + r) / 2, e = no * 2, d = no * 2 + 1;

    update(e, l, m, pos, v);
    update(d, m + 1, r, pos, v);

    seg[no] = seg[e] * seg[d];
}

void build(int no, int l, int r, vector<int> &lista) {
    if (l == r) {
        seg[no] = lista[l - 1];
        return;
    }

    int m = (l + r) >> 1, e = no * 2, d = no * 2 + 1;

    build(e, l, m, lista);
    build(d, m + 1, r, lista);

    seg[no] = seg[e] * seg[d];
}
int n,k;
int main(int argc, char **argv) {
    optimize;
    cin >> n >> k;

    for(int i = 1; i <= 4*n + 1;i++){
        seg[i] = 1;
    }

    vi nums(n);
    for(int i = 1;i <=n;i++){
        cin >> nums[i - 1];
        update(1,1,n,i,nums[i-1]);
    }
    while(k--){
        char op;
        cin >> op;
        if(op == 'C'){
            int i ,v;
            cin >> i >> v;
            int val = query(1,1,n,i,i);
            cout <<"saindo:" << val << endl;
            update(1,1,n,i,v - val);
        }else{
            int l , r;
            cin >> l >> r;
            cout << query(1,1,n,l,r ) << endl;
        }
    }
    return 0;
}

