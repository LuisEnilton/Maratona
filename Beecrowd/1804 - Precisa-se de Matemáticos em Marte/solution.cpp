//
// Created by luise on 21/07/2023.
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
#define MAXN 100101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>
ll bit[MAXN];
int n;
int arr[MAXN];

void update(int x, int val) {
    while (x < MAXN) {
        bit[x] += val;
        x += (x & -x);
    }
}

ll query(int x) {
    ll ret;
    while (x > 0) {
        ret += bit[x];
        x -= (x & -x);
    }
    return ret;
}

int main(int argc, char **argv) {
    optimize;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        update(i, v);
        arr[i] = v;
    }
    string op = "a";
    int pos = 1;
    while ((cin >> op >> pos && (op !="0" && pos !=0))) {
        if (op == "a") {
            update(pos, -arr[pos]);
            arr[pos] = 0;
        } else {
            if(pos > 1)
                cout << query(pos - 1) << endl;
            else
                cout << 0 << endl;
        }
    }

    return 0;
}