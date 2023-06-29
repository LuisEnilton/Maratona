//
// Created by luise on 29/06/2023.
//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <string>
#include <vector>
#include <iostream>
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
#define MAXN 101010
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

vi dim_caixa;
vi dim_jan;

int main(int argc, char const *argv[]) {
    optimize;
    dim_caixa.resize(3);
    dim_jan.resize(2);

    for (auto &x: dim_caixa) {
        cin >> x;
    }

    sort(ALL(dim_caixa));

    for (auto &x: dim_jan) {
        cin >> x;
    }

    sort(ALL(dim_jan));

    bool ans = false;
    if(dim_caixa[0]<= dim_jan[0] && dim_caixa[1] <= dim_jan[1])
        ans = true;

    if (ans)
        cout << "S" << endl;
    else
        cout << "N" << endl;
    return 0;
}


