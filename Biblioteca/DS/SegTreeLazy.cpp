// By SamuellH12
#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>
#define ll long long
const int MAXN = 1e6 + 5;


struct SegTree {

    vector<ll> seg, lazy, nums;
    int n;
    ll NEUTRO = 0;

    SegTree(vector<ll> &nums) {
        n = nums.size();
        seg.resize(4 * n);
        lazy.resize(4 * n);

        this->nums = nums;

        build(1, 1, n, nums);
    }

    ll join(ll a, ll b) {
        return a + b;
    }

    void unlazy(int no, int l, int r) {
        if (lazy[no] == 0) return;

        int m = (l + r) >> 1, e = no * 2, d = no * 2 + 1;

        seg[no] += (r - l + 1) * lazy[no];

        if (l != r) {
            lazy[e] += lazy[no];
            lazy[d] += lazy[no];
        }

        lazy[no] = NEUTRO;
    }

    ll query(int no, int l, int r, int a, int b) {
        unlazy(no, l, r);
        if (b < l || r < a) return NEUTRO;
        if (a <= l && r <= b) return seg[no];

        int m = (l + r) >> 1, e = no * 2, d = no * 2 + 1;

        return query(e, l, m, a, b) + query(d, m + 1, r, a, b);
    }

    void update(int no, int l, int r, int a, int b, ll v) {
        unlazy(no, l, r);
        if (b < l || r < a) return;
        if (a <= l && r <= b) {
            lazy[no] += v;
            unlazy(no, l, r);
            return;
        }

        int m = (l + r) >> 1, e = no * 2, d = no * 2 + 1;

        update(e, l, m, a, b, v);
        update(d, m + 1, r, a, b, v);

        seg[no] = join(seg[e], seg[d]);
    }


    void build(int no, int l, int r, vector<ll> &lista) {
        if (l == r) {
            seg[no] = lista[l - 1];
            return;
        }

        int m = (l + r) >> 1, e = no * 2, d = no * 2 + 1;

        build(e, l, m, lista);
        build(d, m + 1, r, lista);

        seg[no] = join(seg[e], seg[d]);
    }
};


int main() {
    //https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/A
    int n, m;
    cin >> n >> m;
    vector<ll> nums(n, 0);
    SegTree seg(nums);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            l++;
            ll x;
            cin >> x;
            seg.update(1, 1, n, l, r, x);
        } else {
            int pos;
            cin >> pos;
            pos++;
            cout << seg.query(1, 1, n, pos, pos) << endl;
        }
    }
    return 0;
}

/******************************************************

-> Segment Tree - Lazy Propagation com:
	- Query em Range
	- Update em Range

-> Chamadas padrão:
	build(1, 1, n, lista);
	query(1, 1, n, a, b);
	update(1, 1, n, a, b, x);

-> Em que:
|   n    | o tamanho máximo da lista
| [a, b] | o intervalo da busca ou update
|   x    | o novo valor a ser somada no intervalo [a, b]
| lista  | o array de elementos originais

Build:  O(N)
Query:  O(log N)
Update: O(log N)
Unlazy: O(1)

*******************************************************/