#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <string>
#include <algorithm>
#include <set>
#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 100000010
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
#define MAXN 101010
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;

vector<pair<char, int>> pedras;
int q;
int d;
int solve(int pos, bool volta = false, int pulo = 0)
{
    if (pos == -1)
    {
        return min(solve(0,volta,pulo), solve(1,volta,pulo));
    }

    if(pos == 0){
        if(pedras[pos].second > pulo)
            pulo = pedras[pos].second;
        if(volta){
            if(d - pedras[pos].second > pulo)
                pulo = d - pedras[pos].second;
        }
    }
    
    if (pos >= pedras.size()){
        if(d-pedras[pos-1].second > pulo)
            pulo = d-pedras[pos-1].second;
        
        
        if (volta)
            return pulo;
        reverse(ALL(pedras));
        solve(-1, volta = true, pulo = pulo);
    }
    
    
    if (abs(pedras[pos].second - pedras[pos-1].second) > pulo)
    {
        pulo = pedras[pos].second-pedras[pos-1].second;
    }


    if (pedras[pos].first == 'S')
        pedras.erase(pedras.begin() + pos);

    return min(solve(pos + 1, volta, pulo), solve(pos + 2, volta, pulo));
}

int main()
{
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n >> d;
        pedras.resize(n);
        for (int i = 0; i < n; i++)
        {
            int x;
            char c;
            cin >> c;
            cin.ignore(1, '-');
            cin >> x;
            pedras[i] = {c, x};
        }
        sort(ALL(pedras));
        cout << solve(-1) << endl;
    }
}
