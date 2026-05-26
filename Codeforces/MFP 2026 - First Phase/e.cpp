//
// Created by Luis on 06/09/2023.
//
// Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define MAXN 1010101
#define int ll
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

int n, p, s;

int t[3];
int d[3];
vector<vi> sla;
vi curr;

void gen(int i)
{
    sla.push_back(curr);
    if (i == s + 1)
        return;
    for (int j = 0; j < 3; j++)
    {
        curr.push_back(j);
        gen(i + 1);
        curr.pop_back();
    }
}

int calc(vi &a)
{
    if (a.size() == 0)
        return INFLL;
    int volta = 0, tempo = 0;
    // tipo de pneu 0 - macio, 1 - medio, 2 - duro
    for (auto x : a)
    {
        if (volta + d[x] > n)
        {
            int qtd = n - volta;
            tempo += qtd * t[x];
            volta = n;
            break;
        }
        volta += d[x];
        tempo += d[x] * t[x];
        if (volta < n)
            tempo += p;
    }
    return (volta < n ? INFLL : tempo);
}

signed main()
{
    optimize;
    cin >> n >> p >> s;
    for (int i = 0; i < 3; i++)
        cin >> t[i];
    for (int i = 0; i < 3; i++)
        cin >> d[i];

    gen(0);
    int ans = INFLL;
    for (auto &est : sla)
    {
        int val = calc(est);
        ans = min(ans, val);
    }
    cout << ans << endl;
    return 0;
}
