//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cmath>

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
#define vb vector<bool>
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


int main() {
    optimize;
    int t; cin >> t;
    for(int i =1;i<=t;i++){
        cout << "Case " << i << ": ";
        deque<string> hand,pile;
        for(int j = 0; j < 52;j++){
            string s; cin >> s;
            if(j < 27)
                pile.emplace_front(s);
            else
                hand.emplace_front(s);
        }
        int y = 0;
        for(int j = 0; j < 3;j++){
            auto tx = pile.front();
            int x = (tx[0] >= '2' && tx[0] <= '9' ?tx[0] - '0' :10);
            y+=x;
            pile.pop_front();
            for(int k = 0; k < 10-x;k++)
                pile.pop_front();
        }
        for(int j = 0; j < hand.size();j++){
            pile.emplace_front(hand.back());
            hand.pop_back();
        }
        cout << pile[pile.size() - y] << endl;
    }
    return 0;
}

