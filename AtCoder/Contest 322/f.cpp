//
// Created by luise on 09/10/2023.
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
#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>
const int maxn= 5 * 10e5 + 1;


struct Node{
    int segm[2];
    int pfx[2];
    int sfx[2];
    int sum[2];

    void clear(){
        memset(segm,0,sizeof segm);
        memset(pfx,0,sizeof pfx);
        memset(sfx,0,sizeof sfx);
        memset(sum,0,sizeof sum);
    }

    Node(){
        clear();
    }

    Node(char c){
        clear();
        segm[c-'0'] = 1;
        pfx[c-'0'] = 1;
        sfx[c-'0'] = 1;
        sum[c-'0'] = 1;     
    }

    void flip(){
        swap(segm[0],segm[1]);
        swap(pfx[0],pfx[1]);
        swap(sfx[0],sfx[1]);
        swap(sum[0],sum[1]);
    }
};
Node seg[4*maxn];
int lazy[4*maxn];

Node join(Node a,Node b){
    Node ans;
    for(int i = 0;i < 2;i++){
        ans.segm[i] = max({a.segm[i],b.segm[i],a.sfx[i] + b.pfx[i]});
        if(a.sum[(i+1)%2] == 0){
            ans.pfx[i] = max(a.pfx[i],a.sum[i] + b.pfx[i]);
        }else{
            ans.pfx[i] = a.pfx[i];
        }
        if(b.sum[(i+1)%2] == 0){
            ans.sfx[i] = max(b.sfx[i],b.sum[i] + a.sfx[i]);
        }else{
            ans.sfx[i] = b.sfx[i];
        }
        ans.sum[i] = a.sum[i] + b.sum[i];

    }
    return ans;
}

void unlazy(int no, int l, int r){
    if(lazy[no] == 0) return;

    int m=(l+r)>>1, e=no*2, d=no*2+1;
    if(lazy[no] % 2!=0){
        seg[no].flip();
    }

    if(l != r){
        lazy[e] += lazy[no];
        lazy[d] += lazy[no];
    }

    lazy[no] = 0;
}

Node query(int no, int l, int r, int a, int b){
    unlazy(no, l, r);
    if(b <  l || r <  a) return 0;
    if(a <= l && r <= b) return seg[no];

    int m=(l+r)>>1, e=no*2, d=no*2+1;

    return join(query(e, l, m, a, b), query(d, m+1, r, a, b));
}

void update(int no, int l, int r, int a, int b, int v){
    unlazy(no, l, r);
    if(b <  l || r <  a) return;
    if(a <= l && r <= b)
    {
        lazy[no]+= v;
        unlazy(no, l, r);
        return;
    }

    int m=(l+r)>>1, e=no*2, d=no*2+1;

    update(e, l,   m, a, b, v);
    update(d, m+1, r, a, b, v);

    seg[no] = join(seg[e] , seg[d]);
}


void build(int no, int l, int r, string &s){
    if(l == r){
        seg[no] = *new Node(s[l-1]);
        return;
    }

    int m=(l+r)>>1, e=no*2, d=no*2+1;

    build(e, l,   m, s);
    build(d, m+1, r, s);

    seg[no] = join(seg[e] ,seg[d]);
}

int main(int argc, char** argv)
{
    optimize;
    int n,q;
    cin >> n >> q;
    string s; cin >> s;
    build(1,1,n,s);
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int l,r;
            cin >> l >> r;
            update(1,1,n,l,r,1);
        }else{
            int l,r;
            cin >> l >> r;
            auto ans = query(1,1,n,l,r);
            cout << ans.segm[1] << endl;
        }
    }
    return 0;
}

