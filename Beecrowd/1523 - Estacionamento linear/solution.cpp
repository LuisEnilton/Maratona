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

int N, K;

int main()
{
    while ((cin >> N >> K) && (K != 0 || N != 0))
    {
        vector<pair<int, pii>> eventos;

        int c, s;
        for (int i = 1; i <= N; i++)
        {
            cin >> c >> s;
            eventos.EB(c, pii(i, 1));
            eventos.EB(s, pii(i, -1));
        }
        stack<pair<int, pii>> estacionamento;
        sort(ALL(eventos));
        bool ok = true;
        for (auto evento : eventos)
        {
            if (evento.second.second == -1)
            {
                if (estacionamento.top().second.first == evento.second.first)
                {
                    estacionamento.pop();
                }
                else
                {
                    ok = false;
                    break;
                }
            }
            else
            {
                estacionamento.push(evento);
            }
            if(estacionamento.size()> K)
                ok = false;
        }
        if(ok)
            cout << "Sim" << endl;
        else
            cout <<"Nao" <<endl;
    }

    return 0;
}
