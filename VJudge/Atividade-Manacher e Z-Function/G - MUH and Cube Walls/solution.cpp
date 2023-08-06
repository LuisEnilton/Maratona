//
// Created by Luis on 04/08/2023.
//
//
// Created by Luis on 04/08/2023.
//
//
// Created by Luis on 04/08/2023.
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


vi Zfunction(vector<ll> &s) {// trocar um vetor de char por um vetor de inteiros n muda nada
    int n = s.size();
    vi z(n);

    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) z[i] = min(z[i - l], r - i + 1);

        while (z[i] + i < n && s[z[i]] == s[i + z[i]]) z[i]++;

        if (r < i + z[i] - 1) l = i, r = i + z[i] - 1;
    }

    return z;
}

int main(int argc, char **argv) {
    optimize;
    int n, w;
    cin >> n >> w;
    if (w == 1) {
        cout << n << endl;
        return 0;
    }
    vector<ll> bears(n);
    vector<ll> ele(w);
    vector<ll> difsB(n - 1);
    vector<ll> difsE(w - 1);

    for (int i = 0; i < n; i++) {
        cin >> bears[i];
        if (i != 0)
            difsB[i-1] = bears[i] - bears[i - 1];
    }

    //for (auto x: difsB) cerr << x << " ";
    //cerr << endl;

    for (int i = 0; i < w; i++) {
        cin >> ele[i];
        if (i != 0)
            difsE[i - 1] = ele[i] - ele[i - 1];
    }

    //for (auto x: difsE) cerr << x << " ";
   // cerr << endl;

    difsE.reserve(w - 1 + n - 1);
    difsE.insert(difsE.end(), ALL(difsB));

    //for(auto x : difsE) cerr << x << " ";
   // cerr << endl;
    vi prefs = Zfunction(difsE);
    ll ans = 0;
    //for (auto x: prefs) {
    //    cerr << x << " ";
   // }
    //cerr << endl;
    for (int i = w - 1 ; i < n +w - 2;i++) {
        if (prefs[i] >= w - 1) ans++;
    }
    cout << ans << endl;
    return 0;
}


