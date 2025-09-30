//
// Created by Luis on 15/09/2023.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define vi vector<int>
#define PB push_back
#define EB emplace_back
#define MAXN 1010101
#define endl '\n'
#define int ll
using namespace std;


struct SegTree {
    int n;
    vi arr;
    vi seg;
    int NEUTRO = 0;
    //  vetor 0- indexado
    // querie 1 indexado
    SegTree(vi &nums) {
        n = nums.size();
        seg.resize(4 * n);
        this->arr = nums;

        build(1, 1, n);
    }

    int join(int a, int b) {
        return a + b;
    }

    void build(int no, int l, int r) {
        if (l == r) {
            seg[no] = arr[l-1];
            return;
        }

        int e = 2 * no;
        int d = e + 1;
        int mid = (l + r) / 2;
        build(e, l, mid);
        build(d, mid + 1, r);
        seg[no] = join(seg[e], seg[d]);
    }

    void update(int no, int l, int r, int pos, int val) {
        if (r < pos || l > pos) {
            return;
        }

        if (l == r) {
            seg[no] = val;
            return;
        }

        int e = 2 * no;
        int d = e + 1;
        int mid = (l + r) / 2;
        update(e, l, mid, pos, val);
        update(d, mid + 1, r, pos, val);

        seg[no] = join(seg[e], seg[d]);
    }

    int query(int no, int l, int r, int a, int b) {
        if (r < a || l > b) {
            return NEUTRO;
        }

        if (l >= a && r <= b) {
            return seg[no];
        }
        int e = 2 * no;
        int d = e + 1;
        int mid = (l + r) / 2;
        return join(query(e, l, mid, a, b), query(d, mid + 1, r, a, b));
    }
};


int main(int argc, char **argv) {
    optimize;
    int n,m; cin >> n >> m;
    vi nums(n);
    for(auto &x: nums){
        cin >> x;
    }
    auto seg = SegTree(nums);
    while(m--){
        int op; cin >> op;
        if(op == 1){
            int pos; cin >> pos;
            pos++;
            ll val; cin >> val;
            seg.update(1,1,n,pos,val);
        }else{
            int l,r;
            cin >> l >> r;
            l++, r++;
            cout << seg.query(1,1,n,l,r-1) << endl;
        }
    }
    return 0;
}