#include <bits/stdc++.h>
#define INF 1000000010
#define ALL(x) x.begin(), x.end()
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define PB push_back
#define EB emplace_back
#define MAXN 1000010
#define MAXL 23
#define endl '\n'
#define int ll
using namespace std;



struct SparseTable
{
    int n;
    vector<vi> m;

    SparseTable() {};

    SparseTable(vi &a)
    {
        this->n = a.size();
        m = vector<vi>(n, vi(MAXL));
        // O primeiro nivel são os numeros lidos no input
        for (int i = 0; i < n; i++)
            m[i][0] = a[i];

        for (int k = 1; k < MAXL; k++)
        {
            for (int i = 0; i + (1 << k) - 1 < n; i++)
            {
                m[i][k] = min(m[i][k - 1] , m[i + (1 << (k - 1))][k - 1]);
            }
        }
    }

    signed query(int l, int r)
    {
        // RODAR O PRECALC
        int j = __builtin_clz(1) - __builtin_clz(r - l + 1);

        return min(m[l][j], m[r - (1 << j) + 1][j]);
    }
};

struct SuffixArray
{
    vi p, rnk, lcp;
    string s;
    int n;
    SparseTable st;
    void count_sort()
    {
        vi cnt(n), new_p(n), pos(n);
        for (auto x : rnk)
            cnt[x]++;
        for (int i = 1; i < n; i++)
            pos[i] = pos[i - 1] + cnt[i - 1];
        for (auto x : p)
            new_p[pos[rnk[x]]++] = x;
        p = new_p;
    }
    SuffixArray(string &s2)
    {
        s = s2 + "$";
        n = s.size();
        p.resize(n);
        rnk.resize(n);
        lcp.resize(n);
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; i++)
            a[i] = {s[i], i};
        sort(ALL(a));
        for (int i = 0; i < n; i++)
            p[i] = a[i].second;
        rnk[p[0]] = 0;
        for (int i = 1; i < n; i++)
            rnk[p[i]] = rnk[p[i - 1]] + (a[i].first != a[i - 1].first);
        for (int k = 0; (1 << k) < n; k++)
        {
            for (int i = 0; i < n; i++)
                p[i] = (p[i] - (1 << k) + n) % n;
            count_sort();
            vi new_rank(n);
            new_rank[p[0]] = 0;
            for (int i = 1; i < n; i++)
            {
                pii prev = {rnk[p[i - 1]], rnk[(p[i - 1] + (1 << k)) % n]}, now = {rnk[p[i]], rnk[(p[i] + (1 << k)) % n]};
                new_rank[p[i]] = new_rank[p[i - 1]] + (now != prev);
            }
            rnk = new_rank;
        }

        build_lcp();
        st = SparseTable(lcp);
    }
    // upperbound - lowerbound
    
    int lb(string &t){
        int sz = t.size(), l = 0, r = n - 1, lb = n;
        while (l <= r)
        {
            int m = (l + r) / 2, idx = p[m];
            auto x = s.substr(idx, min(n - 1 - idx, sz));
            if (x >= t)
                r = m - 1, lb = m;
            else
                l = m + 1;
        }
        return lb;
    }

    int ub(string &t){
        int sz = t.size(), l = 0, r = n - 1, up = n;
        while (l <= r)
        {
            int m = (l + r) / 2, idx = p[m];
            auto x = s.substr(idx, min(n - 1 - idx, sz));
            if (x > t)
                r = m - 1, up = m;
            else
                l = m + 1;
        }
        return up;
    }
    
    int count(string &t)
    {
        return ub(t) - lb(t);
    }

    void build_lcp()
    {
        int k = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int pi = rnk[i]; // position of suffix i in suffix array
            if(pi == 0) continue;
            int j = p[pi - 1];
            // lcp[i] = lcp
            while (s[i + k] == s[j + k])
                k++;
            lcp[pi] = k;
            k = max(k - 1, 0LL);
        }
    }
};