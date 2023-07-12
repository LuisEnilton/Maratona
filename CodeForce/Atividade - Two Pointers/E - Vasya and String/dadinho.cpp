//
// Created by Luis on 11/07/2023.
//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
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


int main(int argc, char** argv)
{
    optimize;

    int N, K;

    cin >> N >> K;

    string S;

    cin >> S;

    int freq_a = 0, freq_b = 0;

    int ans = 0, l = 0;

    for (int r = 0; r < N; r++)
    {
        (S[r] == 'a') ? freq_a++ : freq_b++;

        while (freq_a > K && freq_b > K)
            (S[l++] == 'a') ? freq_a-- : freq_b--;

        ans = max(ans, r - l + 1);
    }

    cout << ans << endl;

    return 0;
}