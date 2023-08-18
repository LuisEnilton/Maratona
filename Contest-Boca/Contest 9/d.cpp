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

int N;

int LIS(vi &nums)
{
    vi pilha;

    for (auto x : nums)
    {
        auto it = upper_bound(ALL(pilha), x);

        if (it == pilha.end())
            pilha.PB(x);
        else
            *it = x;
    }

    return pilha.size();
}

vi ordem = {0, 1, 2};

int main(int argc, char** argv)
{
    optimize;

    cin >> N;

    vi nums(N);

    for (auto &x : nums) cin >> x;

    int ans = 0;

    do
    {
        auto curr = nums;

        for (auto &x : curr)
            x = ordem[x];

        ans = max(ans, LIS(curr));
    }
    while(next_permutation(ALL(ordem)));


    cout << ans << endl;

    return 0;
}
