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
    cout.tie(NULL)
#define INF 1000000010
#define INFLL 1000000000000000010LL
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
#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'
#define int ll
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

int n, c;
vector<vi> cl;

int calc(vi &idx)
{
    int maxi = 0;
    int mini = INFLL;
    for (int i = 0; i < 4; i++)
    {
        maxi = max(cl[i][idx[i]], maxi);
        mini = min(cl[i][idx[i]], mini);
    }

    return maxi - mini;
}

signed main()
{
    optimize;

    for (int i = 0; i < 4; i++)
    {
        int n;
        cin >> n;
        vi a(n);
        for (auto &x : a)
            cin >> x;
        sort(ALL(a));
        cl.PB(a);
    }

    int aux = INFLL;
    vi ans;
    for (int i = 0; i < cl[0].size(); i++)
    {
        for (int j = 0; j < cl[1].size(); j++)
        {
            for (int k = 0; k < cl[2].size(); k++)
            {
                for (int l = 0; l < cl[3].size(); l++)
                {
                    vi idx = {i,j,k,l};
                    int sum = calc(idx);
                    if(sum < aux){
                        ans = idx;
                        aux = sum;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        cout << cl[i][ans[i]] << " ";
    }
    cout << endl;
    return 0;
}