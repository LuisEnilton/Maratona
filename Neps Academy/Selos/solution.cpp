//
// Created by Luis on 21/07/2023.
//
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

ll q;


bool crivo(ll N)
{
    vector<int> eh_primo( (int) floor(sqrt(N)) + 1, 1);

    eh_primo[0] = eh_primo[1] = 0;

    int pos = 1;

    for (ll i = 2; i * i <= N; i++)
    {
        if (!eh_primo[i]) continue;

        if(N % i == 0) return false;

        // i é primo

        for (ll j = i * i; j <= (int) sqrt(N); j += i)
            eh_primo[j] = 0;
    }

    return  true;
}

ll teste = 10e10;
int main(int argc, char** argv)
{
    optimize;
    cin >> q;
    cout <<"SN"[crivo(q)] << endl;

    return 0;
}