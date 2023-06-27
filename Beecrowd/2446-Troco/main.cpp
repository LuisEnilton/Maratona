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
#define MAX_MOEDAS 1010
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;

int N;
vi moedas;
int qtd;
bool dp[MAXN][MAX_MOEDAS];
bool vis[MAXN][MAX_MOEDAS];


/*bool solve(int n, int i) {
    if (n == 0)
        return true;
    if (n < 0) return false;
    if (i >= qtd) return false;


    if (vis[n][i]) return dp[n][i];

    vis[n][i] = true;

    if(solve(n-moedas[i],i+1))
        return dp[n][i] = true;

    if(solve(n,i+1))
        return  dp[n][i]= true;

    return dp[n][i] = false;
}*/

bool solve(int N, int moeda) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= qtd; j++) {
            if (i == 0) return true;
            else if (j == 0) dp[i][j] = false;
            else {
                dp[i][j] = dp[i][j - 1];
                if(dp[i][j] == true) continue;

                if (i - moedas[j - 1] >= 0) {
                    int novo_troco_se_usar_moeda = i - moedas[j - 1];
                    dp[i][j] =  dp[novo_troco_se_usar_moeda][j - 1];
                }
            }
        }
    }
    return dp[N][qtd];
}

int main() {
    optimize;
    memset(dp, -1, sizeof dp);
    cin >> N >> qtd;
    moedas.resize(qtd);
    for (int &x: moedas) {
        cin >> x;

    }
    if (solve(N, 0)) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }
//cout<< solve(N) ? "S" : "N"
//cout <<"NS"[solve(N)] <<endl;
}
