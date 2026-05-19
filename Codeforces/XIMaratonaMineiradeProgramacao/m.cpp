#include <bits/stdc++.h>

#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define dbg(x) cout << #x << " " << x << endl;
#define ALL(x) x.begin(), x.end()
using namespace std;

using ll = long long;
#define int ll
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q, n, T;
    cin >> q >> n >> T;

    vii a(q);
    multiset<ii> by_d, by_t;
    for (auto &[d, t] : a)
        cin >> d >> t;
    sort(ALL(a),[&](ii & x, ii & y){
        return x.second < y.second;
    });

    vii c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i].first;
        c[i].second = i;
    }

    sort(ALL(c));

    int ans = 0;
    int curr = 0;
    for (auto &[d, t] : a)
    {
        // cout << d << " " << t << endl;
        if (curr + t <= T)
        {
            // consigo pegar
            curr += t;
            ans++;
            by_d.emplace(d, t);
        }
        else
        {
            by_t.emplace(t, d);
        }
    }
    sort(ALL(a));
    reverse(ALL(a));
    int j = 0;
    vi resp(n);
    for (int i = n - 1; i >= 0; i--)
    {
        // dbg(ans);
        // dbg(curr);
        auto [inteli, id] = c[i];
        // dbg(inteli);
        while (j < q && inteli < a[j].first)
        {
            // dbg(a[j].first);
            auto [d, t] = a[j];
            auto aux1 = make_pair(d, t);
            auto aux2 = make_pair(t, d);
            if (by_d.count(aux1))
            {

                by_d.erase(by_d.find(aux1));
                ans--;
                curr -= t;
            }
            if (by_t.count(aux2))
                by_t.erase(by_t.find(aux2));
            j++;
        }
        // dbg(curr);
        // dbg((*by_t.begin()).first);
        // dbg(by_t.size());
        while (by_t.size() && curr + (*by_t.begin()).first <= T)
        {
            auto [t,d] = *by_t.begin();
            curr += t;
            ans++;
            by_d.emplace(d,t);
            by_t.erase(by_t.begin());
        }
        resp[id] = ans;
    }

    for (auto x : resp)
    {
        cout << x << endl;
    }
}