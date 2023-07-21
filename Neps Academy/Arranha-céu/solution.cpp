//
// Created by luise on 10/07/2023.
//
//Template By eduardocesb
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
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
//#define MAXN 10e5+100;
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>


const int MAXN = 10e5 + 100;


int tree[MAXN * 4];

void update(int pos, int i, int j, int x, int val) {
    int esquerda = 2 * pos;
    int direita = 2 * pos + 1;
    int mid = (i + j) / 2;
    tree[pos] += val;
    if (i == j) return;
    if (x <= mid) update(esquerda, i, mid, x, val);
    else
        update(direita, mid + 1, j, x, val);
}

ll query(int pos, int i, int j, int l, int r) {
    int esquerda = 2 * pos;
    int direita = 2 * pos + 1;
    int mid = (i + j) / 2;

    if (i > r || j < l) return 0;
    if (i >= l && j <= r) return tree[pos];
    else return query(esquerda, i, mid, l, r) + query(direita,mid+1,j,l,r);
}


int main(int argc, char **argv) {

    int n, q;
    cin >> n >> q;
    for(int i = 0;i < n;i++){
        int v;
        cin >> v;
        update(1,0,n-1,i,v);
    }
    while(q --){
        int op;
        cin >> op;
        if(op == 0){
            int ap,p;
            cin >> ap >> p;
            ll atual = query(1, 0 , n-1,ap-1,ap-1);
            update(1,0,n-1,ap - 1,-1 * atual); // zera
            update(1,0,n-1,ap - 1,p);
        }else{
            int k;
            cin >> k;
            k--;
            cout << query(1,0,n-1,1-1,k) << endl;
        }
    }


    return 0;
}