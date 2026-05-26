#include <bits/stdc++.h>
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
using namespace std;
const long inf = 1e18;

int solve()
{
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<int>> h(m + 1);
    vector<int> l(k + 1); // 0 - , 1 - na fila , 2 - liberado
    vector<int> f(k + 1);
    vector<int> cnt(k + 1); // contador do cara na fila
    vector<vector<int>> times(k + 1);
    vector<int> prox(k + 1);
    set<pair<int, int>> s;
    int aval = 0;
    for (int i = 1; i <= n; ++i)
    {
        int t, p;
        cin >> t >> p;
        h[t].push_back(p);
        f[p]++;
        times[p].push_back(t); 
        // segunda vez que ele aparece
    }

    for(int i = 1; i <=k;i++){
        if(times[i].size() < 2) continue;
        sort(times[i].begin(),times[i].end());
        // dbg(i);
        prox[i] = times[i][1];
    }
    int done = 0;
    int final = 0;

    for (int i = 1; done < n; i++)
    {
        // entrando um cara desse tipo
        if (i <= m)
        {

            for (auto p : h[i])
            {
                if (l[p] == 2)
                {
                    aval++;
                }else if(l[p] == 1){
                    cnt[p]++;
                }
                else if (f[p] == 1)
                {
                    l[p] = 1;
                    s.emplace(inf, p);
                }
                else
                {
                    l[p] = 1;
                    s.emplace(prox[p], p);
                }
            }
        }
        if (aval)
        {
            aval--;
            done++;
        }
        // kan
        if (s.empty())
        {
            if (aval)
            {
                aval--;
                done++;
            }
        }
        else
        {
            auto [pro, p] = *s.begin();
            s.erase(s.begin());
            l[p] = 2;
            aval += cnt[p];
            done++;
        }
        final = i;
    }

    return final;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    freopen("clar.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
        cout << solve() << '\n';
    return 0;
}
