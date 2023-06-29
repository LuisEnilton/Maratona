//
// Created by Luis on 27/06/2023.
//
//
// Created by Luis on 27/06/2023.
//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <string>
#include <algorithm>
#include <set>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 100000010
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101
#define MAXN 1010010
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;

int N, K;
string s;

int main() {
    optimize;
    cin >> N;
    cin >> s;
    int cont = 0;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (s[i] == 'a') cont++;
        else {
            if (cont > 1) ans += cont;
            cont = 0; //acha um b reseta o cont
        }
    }
    if (cont > 1) ans += cont;//se tiver um seq no final
    cout << ans << endl;
}




