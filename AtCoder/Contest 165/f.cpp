//
// Created by Luis on 09/10/2023.
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


vector<ll> nums;
vi ans;
const int maxn = 2 * 10e5 + 2;
vi grafo[maxn];
vector<ll> arr;


void dfs(int o, int p = -1) {
    ll prev, pos = -1;
    bool troca = false;
    auto it
            = lower_bound(arr.begin(), arr.end(), nums[o]);
    if (it == arr.end()) {
        pos = arr.size() - 1;
        arr.push_back(nums[o]);//se n tiver ngm maior ou igual
    } else {
        troca = true;
        pos = it - arr.begin();
        prev = arr[pos];
        arr[pos] = nums[o];
    }
    ans[o] = arr.size();
    for (auto x: grafo[o]) {
        if (x != p)
            dfs(x, o);
    }
    if (troca) {
        arr[pos] = prev;
    } else {
        arr.pop_back();
    }
}

int main(int argc, char **argv) {
    optimize;
    int n;
    cin >> n;
    nums.resize(n + 1);
    ans.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        grafo[u].EB(v);
        grafo[v].EB(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    string s = "as";
    return 0;
}

