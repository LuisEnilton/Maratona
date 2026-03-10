#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

vi pi(string &s)
{

    int n = s.size();
    vi p(n);
    p[0] = 0;

    vi cnt(n);

    for (int i = 1; i < n; i++)
    {

        int k = p[i - 1];

        while (k > 0 && s[k] != s[i])
            k = p[k - 1];
        p[i] = k + (s[i] == s[k]);
    }
    return p;
}