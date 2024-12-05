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
#define vb vector<bool>
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
#define int ll
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>
typedef pair<pii, int> rng;

struct Range {
    int l{}, r{}, id{};

    Range(int l, int r, int id) {
        this->l = l;
        this->r = r;
        this->id = id;
    }

    Range() {
    };

    bool operator<(const Range &rng) const {
        if (r == rng.r) {
            return l > rng.l;
        }
        return r < rng.r;
    }
};

bool pred(Range &a, Range &b) {
    if (a.r == b.r) {
        return a.l < b.l;
    }
    return a.r > b.r;
}


int bit[MAXN];
int arr[MAXN];

void upd(int x, ll v) {
    while (x < MAXN) {
        bit[x] += v;
        x += (x & -x);
    }
}

ll qry(int x) {
    ll ret = 0;

    while (x > 0) {
        ret += bit[x];
        x -= (x & -x);
    }
    return ret;
}

unordered_map<int,ll> mapa;

void compressor(vector<int> &a) {
    int n = a.size();
    vector<pair<int, int> > pairs(n);
    for (int i = 0; i < n; ++i) {
        pairs[i] = {a[i], i};
    }
    sort(pairs.begin(), pairs.end());
    int nxt = 1;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && pairs[i - 1].first != pairs[i].first) nxt++;
        a[pairs[i].second] = nxt;
        mapa[pairs[i].first] = nxt;
    }
}


signed main() {
    //optimize;
    int n;
    cin >> n;
    vector<Range> rngs;
    vi ans(n);
    vi a;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.PB(x);
        a.PB(y);
        rngs.EB(x, y, i);
    }

    /*for (auto x: a) {
        cout << x << " ";
    }
    cout << endl;*/
    UNIQUE(a);
    /*for (auto x: a) {
        cout << x << " ";
    }
    cout << endl;*/
    compressor(a);
    /*for (auto x: a) {
        cout << x << " ";
    }
    cout << endl;*/

    for (auto &[l,r,id]: rngs) {
        l = mapa[l];
        r = mapa[r];
    }

    sort(ALL(rngs));
    // Ordena pelo menor R, para uma posição i. Os ranges contidos neles são os que tem l maior ou =  do que o atual
    for (auto [l,r,id]: rngs) {
        int q = qry(r) - qry(l - 1);
        ans[id] = q;
        upd(l, 1);
    }

    for (auto x: ans) cout << x << " ";
    cout << endl;

    sort(ALL(rngs), pred);

    fill(bit, bit + MAXN, 0);

    // Ordena pelo maior R, para uma posição i.
    // Os ranges que contém ele são os que tem l menor do que o atual
    for (auto [l,r,id]: rngs) {
        ans[id] = qry(l);

        upd(l, 1);
    }

    for (auto x: ans) cout << x << " ";
    cout << endl;
    return 0;
}
