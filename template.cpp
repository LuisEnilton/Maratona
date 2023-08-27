//Template By eduardocesb
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

int mostSignificantOne(bitset<64> bt){
    int pos = 0;
    int ans = 0;
    while(pos != bt.size()){
        pos = bt._Find_next(pos);
        if(pos!=bt.size())
            ans = pos;
    }

    return ans;
}
int counterGame(long n) {
    bitset<64> bt(n);
    int cont = 0;
    while(n > 1){
        if(bt.count() == 1){
            n>>=1;
            bt>>= 1;
        }else{
            int pos = mostSignificantOne(bt);
            n-= (1 << pos);
            bitset<64> copy(n);
            bt.reset();
            bt |= copy;
        }
        cont++;
    }

    return cont;
}
int main(int argc, char** argv)
{
    optimize;
    cout <<counterGame(6);
    return 0;
}

