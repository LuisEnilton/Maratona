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
const int maxn = 2e5+10;
int seg[maxn];
int lazy[maxn];


void update(int p, int l, int r, int a, int b, int v){
    if(lazy[p]){
        seg[p] += (r-l+1)*lazy[p];
        if(l != r){
            lazy[2*p] += lazy[p];
            lazy[2*p+1] += lazy[p];
        }
        lazy[p] = 0;
    }
    if(l > b || r < a) return;
    if(l >= a && r <= b){ // se o intervalo estiver contido
        seg[p] += (r-l+1)*v;
        if(l != r){ // se não for folha
            lazy[2*p] += v; // atualiza o lazy dos filhos
            lazy[2*p+1] += v;
        }
        return;
    }
    int m = (l+r)/2;
    update(2*p, l, m, a, b, v);
    update(2*p+1, m+1, r, a, b, v);
    seg[p] = seg[2*p] + seg[2*p+1];
}
// essa função seta todos os valores no intervalo [a,b] para v
void updateSet(int p, int l, int r, int a, int b, int v){
    if(lazy[p]){
        seg[p] += (r-l+1)*lazy[p];
        if(l != r){
            lazy[2*p] += lazy[p];
            lazy[2*p+1] += lazy[p];
        }
        lazy[p] = 0;
    }
    if(l > b || r < a) return;
    if(l >= a && r <= b){
        seg[p] = (r-l+1)*v; // seta o valor do nó
        if(l != r){
            lazy[2*p] = v; // seta o lazy dos filhos
            lazy[2*p+1] = v;
        }
        return;
    }
    int m = (l+r)/2;
    updateSet(2*p, l, m, a, b, v);
    updateSet(2*p+1, m+1, r, a, b, v);
    seg[p] = seg[2*p] + seg[2*p+1];
}

int query(int p, int l, int r, int a, int b){
    if(lazy[p]){ // se tiver lazy
        seg[p] += (r-l+1)*lazy[p]; // atualiza o valor do nó
        if(l != r){ // se não for folha
            lazy[2*p] += lazy[p]; // atualiza o lazy dos filhos
            lazy[2*p+1] += lazy[p];
        }
        lazy[p] = 0; // zera o lazy do nó
    }
    if(l > b || r < a) return 0;
    if(l >= a && r <= b) return seg[p];
    int m = (l+r)/2;
    return query(2*p, l, m, a, b) + query(2*p+1, m+1, r, a, b);
}


void build(int p, int l, int r,vi &nums){
    if(l == r){ // se for folha
        seg[p] = nums[l-1];// coloca o valor correspondente
        return;
    }
    int m = (l+r)/2;
    build(2*p, l, m,nums);
    build(2*p+1, m+1, r,nums);
    seg[p] = seg[2*p] + seg[2*p+1];
}

int main(int argc, char** argv)
{
    optimize;
    int n, q;
    cin >> n >> q;
    vi nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    build(1, 1, n, nums);
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int a, b, v;
            cin >> a >> b >> v;
            update(1, 1, n, a, b, v);
        }if(t==2){
            int a ,b,v;
            cin >> a >> b >> v;
            updateSet(1, 1, n, a, b, v);
        }
        if(t==3){
            int a, b;
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << endl;
        }
    }
    return 0;
}
//4 5 6 4 5
