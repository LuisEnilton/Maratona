#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 1000000010
#define INFLL 1000000000000000010LL
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



/*
 * Complete the 'counterGame' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts LONG_INTEGER n as parameter.
 */

ll mostSignificantOne(bitset<64> bt){
    ll pos = 0;
    ll ans = 0;
    while(pos!=bt.size()){
        pos = bt._Find_next(pos);
        if(pos !=bt.size())
            ans = pos;
    }

    return ans;
}



string counterGame(ll n) {
    bitset<64> bt(n);
    int cont = 0;
    while(n > 1){
        if(bt.count() == 1){
            n>>=1;
            bt>>= 1;
        }else{
            ll pos = mostSignificantOne(bt);
            ll a = 1;
            n-= (a << pos);
            bitset<64> copy(n);
            bt.reset();
            bt |= copy;
        }
        cont++;
    }
    return ((cont & 1)?"Louise":"Richard");
}

int main()
{
    optimize;
    int t; cin >> t;



    for (int t_itr = 0; t_itr < t; t_itr++) {
        ll n; cin >> n;

        string result = counterGame(n);

        cout << result << endl;
    }


    return 0;
}


