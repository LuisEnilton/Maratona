//
// Created by Luis on 14/01/2024.
//
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


int main() {
    optimize;
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vi indo, vindo;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            if (s[i] == 'a') indo.PB(i + 1);
            else vindo.PB(i + 1);
        }
    }
    if ((indo.size() + vindo.size()) & 1) {
        cout << -1 << endl;
        return 0;
    }
    int total = indo.size() + vindo.size();
    bool troca = (indo.size() & 1) || (vindo.size() & 1);
    cout << (troca ? total/2 + 1 : total/2) << endl;
    if ((indo.size() & 1) || (vindo.size() & 1)) {
        auto i = vindo.back();
        vindo.pop_back();
        cout << i << " " << i << endl;
        indo.push_back(i);
    }
    for (int i = 0; i < indo.size() / 2; i++) {
        cout << indo[i] << " " << indo[i + 1] << endl;
    }
    for (int i = 0; i < vindo.size() / 2; i++) {
        cout << vindo[i] << " " << vindo[i + 1] << endl;
    }
    return 0;
}

