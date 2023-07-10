//
// Created by luise on 10/07/2023.
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

int t;

int main(int argc, char **argv) {
    optimize;
    cin >> t;

    cin.ignore();
    string s;
    getline(cin, s );
    while (t--) {
       // cout << "opa" << endl;
        int total = 0;
        map<string, int> arvores;

        string linha = "asd";
        while (linha != "") {
            getline(cin, linha);
            if (linha == "") break;
            if (arvores.count(linha) == 0) arvores[linha] = 1;
            else arvores[linha]++;
            total++;
        }
        for (auto arvore: arvores) {
            cout << arvore.first << " " << setprecision(4) << fixed << 100 * (double) arvore.second / total << endl;
        }
        if(t > 0) cout<<""<<endl;
    }

    return 0;
}