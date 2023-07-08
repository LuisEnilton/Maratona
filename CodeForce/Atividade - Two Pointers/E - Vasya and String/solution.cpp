//
// Created by Luis on 08/07/2023.
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

int n, k;
string s;

int solve( char l) {
    int m = k; // numero de mudanças disponiveis

    queue<int> inicio;

    inicio.push(0);

    int beauty = 0, ans = 1;

    while (!inicio.empty()) {
        int i = inicio.front();
        int j = i;
        inicio.pop();

        while (i < n) {
            if (j == n) break;

            if (l == s[j]) {
                beauty++;
                j++;
            } else {
                if (m > 0) { // se tiver trocas ->troca e coloca o da frente na fila
                    beauty++;
                    j++;
                    m--;
                    inicio.push(j);
                } else {
                    inicio.push(j+1);
                    break;
                }
            }
        }
        if (beauty > ans) ans = beauty;
        beauty = 0, m = k; //resetar valores
    }

//aabaabaa
    return ans;
}

int main(int argc, char **argv) {
    optimize;
    cin >> n >> k;


    cin >> s;

    cout << max(solve('a'),solve('b'));


    return 0;
}