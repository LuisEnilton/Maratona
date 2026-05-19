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
#define EPS 1e-6
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'
#define pid pair<int, double>
#define vid vector<pid>
using namespace std;

struct Queue
{
    stack<pair<double, double>> in, out;
    double NEUTRO = 1e9;
    double join(double a, double b)
    {
        return min(a, b);
    }
    void push(double x)
    {
        if (in.empty())
        {
            in.emplace(x, x);
        }
        else
        {
            in.emplace(x, join(x, in.top().second));
        }
    }

    bool empty()
    {
        return in.empty() && out.empty();
    };

    void pop()
    {
        if (out.empty())
        {
            while (!in.empty())
            {
                auto x = in.top().first;
                in.pop();
                if (out.empty())
                    out.emplace(x, x);
                else
                    out.emplace(x, join(x, out.top().second));
            }
        }
        out.pop();
    }

    double top()
    {
        double ans1 = in.size() ? in.top().second : NEUTRO;
        double ans2 = out.size() ? out.top().second : NEUTRO;
        return join(ans1, ans2);
    }
};

signed main()
{
    optimize;
    int n, k;
    cin >> n >> k;

    // eu quero calcular o maior subarray numa ps, mas o tamanho dele tem que ser maior do K

    vi a(n);
    unordered_map<int, vi> idxs;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        idxs[a[i]].push_back(i);
    }

    unordered_map<int, int> freq;
    unordered_map<int, int> cnt_freq;
    freq.max_load_factor(0.25);
    freq.reserve(n);
    cnt_freq.max_load_factor(0.25);
    cnt_freq.reserve(n);
    int maxi = 0;

    auto add = [&](int x)
    {
        cnt_freq[freq[x]]--;
        freq[x]++;
        cnt_freq[freq[x]]++;
        maxi = max(maxi, freq[x]);
    };

    auto remove = [&](int x)
    {
        cnt_freq[freq[x]]--;
        if (cnt_freq[freq[x]] == 0)
            maxi--;
        freq[x]--;
        cnt_freq[freq[x]]++;
    };

    auto qry = [&]()
    {
        // dbg(maxi);
        // dbg(k);
        return (double)maxi / k;
    };
    double ans = 0.0;
    for (int i = 0; i < k; i++)
    {
        add(a[i]);
    }
    ans = max(ans, qry());
    for (int i = k; i < n; i++)
    {
        remove(a[i - k]);
        add(a[i]);
        ans = max(ans, qry());
    }
    // dbg(ans);
    auto can = [&](double x)
    {
        // dbg(x);
        double ans = -1e9;

        for (auto &[val, arr] : idxs)
        {
            double min_val = 1e9;
            queue<pid> q; // o subarray tem que ter tamanho >=k
            q.emplace(k - 1, 0.0);
            int ptr = 0;
            for (int idx = 0; idx < arr.size(); idx++)
            {
                while (q.size() && q.front().first <= arr[idx])
                {
                    min_val = min(min_val, q.front().second);
                    q.pop();
                }
                int cnt = idx + 1;
                double curr = cnt - x * (arr[idx] + 1);
                double prev_sum = idx - x * arr[idx];
                q.emplace(arr[idx] + k - 1, prev_sum); // daqui a k posições eu vou poder usar esse valor
                // tenho calcular o valor K posições pra tras,
                while (ptr < arr.size() && arr[ptr] <= arr[idx] - k) ptr++;
                double ps_atras = ptr - x * (arr[idx] - k + 1);
                if (arr[idx] >= k)
                    ans = max(ans, curr - ps_atras);
                ans = max(ans, curr - min_val);
            }
        }
        // dbg(ans);
        return ans >= 0;
    };
    double ans2 = 0.0;
    double l = 0.0, r = 1.0;
    while (abs(r - l) >= EPS)
    {

        auto m = (l + r) / 2;
        if (can(m))
        {
            ans2 = m;
            l = m;
        }
        else
        {
            r = m;
        }
    }
    ans = max(ans, ans2);
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}
