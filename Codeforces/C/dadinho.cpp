//
// Created by Luis on 05/09/2023.
//
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define pii pair<int, int>
#define ll long long
#define vi vector<int>
#define vii vector<pii>
#define MAXN 100010
#define endl '\n'

using namespace std;

int seg[4 * MAXN];

int nums[MAXN], N, ans[MAXN];
vi grafo[MAXN];

int query(int no, int l, int r, int a, int b)
{
    if (a > r || b < l) return 0;
    if (a <= l && r <= b) return seg[no];

    int e = 2 * no;
    int d = e + 1;
    int m = (l + r) / 2;

    return max(query(e, l, m, a, b), query(d, m + 1, r, a, b));
}

void update(int no, int l, int r, int pos, int v)
{
    if (l == r)
    {
        seg[no] = v;
        return;
    }

    int e = 2 * no;
    int d = e + 1;
    int m = (l + r) / 2;

    if (pos <= m)
        update(e, l, m, pos, v);
    else
        update(d, m + 1, r, pos, v);

    seg[no] = max(seg[e], seg[d]);
}

void dfs(int u, int p = -1)
{
    int curr = query(1, 1, N, 1, nums[u] - 1);
    int backup = query(1, 1, N, nums[u], nums[u]);

    update(1, 1, N, nums[u], curr + 1);


    ans[u] = query(1, 1, N, 1, N);

    for (auto v : grafo[u])
        if (v != p)
            dfs(v, u);

    update(1, 1, N, nums[u], backup);
}

int main()
{
    cin >> N;

    for (int i = 2, p; i <= N; i++)
    {
        cin >> p;

        grafo[i].push_back(p);
        grafo[p].push_back(i);
    }

    vi a;

    for (int i = 1; i <= N; i++)
    {
        cin >> nums[i];
        a.push_back(nums[i]);
    }

    sort(ALL(a));
    UNIQUE(a);

    for (int i = 1; i <= N; i++)
        nums[i] = lower_bound(ALL(a), nums[i]) - a.begin() + 1;

    dfs(1);

    for (int i = 2; i <= N; i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}