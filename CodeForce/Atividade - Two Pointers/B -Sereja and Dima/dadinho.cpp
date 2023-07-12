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

    int N;

    cin >> N;

    int l = 0, r = N - 1;

    vi nums(N);

    for (int &x : nums) cin >> x;

    int sereja = 0, dima = 0;

    for (int i = 0; i < N; i++)
    {
        if (nums[l] > nums[r])
        {
            (i & 1 ? dima : sereja) += nums[l++];
        }
        else
        {
            (i & 1 ? dima : sereja) += nums[r--];
        }
    }

    cout << sereja << " " << dima << endl;

    return 0;
}
