#include <bits/stdc++.h>
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
#define MAXN 505050
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;

#define dbg_loc() cerr << __PRETTY_FUNCTION__ << " : " << __LINE__ << "\n"
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p){
    return os << '(' << p.first << ", " << p.second << ')';
}
template<typename T_container,typename T=typename enable_if<!is_same<T_container,string>::value, typename T_container::value_type>::type>
ostream& operator<<(ostream &os, const T_container &v){
    os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}';
}
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){
    cerr << ' ' << H;
    dbg_out(T...);
}
#define LOCAL
#ifdef LOCAL
#define dbg(...) cerr<<"(" << #__VA_ARGS__<<"):" , dbg_out(__VA_ARGS__) , cerr << endl
#else
#define dbg(...)
#endif

/*
 
LCA = Lowest Common Ancestor => Menor Ancestral Comum
 
*/

int N, nums[MAXN], nivel[MAXN], dp[MAXN][MAXL], dp_maior[MAXN][MAXL];

vi grafo[MAXN];
vi posicoes[MAXN];

void dfs(int u, int p = -1)
{


    if (p != -1)
        nivel[u] = nivel[p] + 1;

    for (auto v : grafo[u])
        if (v != p)
        {
            dp[v][0] = u;
            // dp_maior[v][0] = custo;
            dfs(v, u);
        }
}

// (2 ^ (i - 1)) + (2 ^ (i - 1)) = 2 ^ i

// p = dp[u][i - 1]

//dp[u][i] = dp[p][i - 1]

void precalc()
{
    memset(dp_maior, -1, sizeof dp_maior);
    memset(dp, -1, sizeof dp);

    dfs(1);

    // O(N * log N)
    for (int i = 1; i < MAXL; i++)
        for (int u = 1; u <= N; u++)
        {
            int p = dp[u][i - 1];

            if (p == -1)
                continue;

            int pai_do_pai = dp[p][i - 1];

            if (pai_do_pai == -1)
                continue;

            dp[u][i] = pai_do_pai;
            dp_maior[u][i] = max(dp_maior[u][i - 1], dp_maior[p][i - 1]);
        }
}

// O(log N) Tempo
int LCA(int u, int v)
{
    int maior = -INF;

    if (nivel[u] < nivel[v])
        swap(u, v);

    for (int i = MAXL - 1; i >= 0; i--)
    {
        if (dp[u][i] == -1)
            continue;

        if (nivel[dp[u][i]] >= nivel[v])
        {
            maior = max(maior, dp_maior[u][i]);
            u = dp[u][i];
        }
    }

    if (u == v)
        return u;

    for (int i = MAXL - 1; i >= 0; i--)
    {
        if (dp[u][i] == -1 || dp[v][i] == -1)
            continue;

        if (dp[u][i] != dp[v][i])
        {
            maior = max({maior, dp_maior[u][i], dp_maior[v][i]});
            u = dp[u][i];
            v = dp[v][i];
        }
    }

    maior = max({maior, dp[u][0], dp[v][0]});

    return maior;
    // return dp[u][0];
}

int dist(int u, int v)
{
    int lca = LCA(u, v);

    return nivel[u] + nivel[v] - 2 * nivel[lca];
}

int main(int argc, char** argv)
{
    optimize;

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> nums[i];

        posicoes[nums[i]].PB(i);
    }


    for (int i = 1, u, v; i < N; i++)
    {
        cin >> u >> v;

        grafo[u].PB(v);
        grafo[v].PB(u);
    }

    precalc();

    ll ans = 0;

    for (int i = 1; i <= N / 2; i++)
    {
        int u = posicoes[i][0];
        int v = posicoes[i][1];

        ans += dist(u, v);
    }

    cout << ans << endl;


    return 0;
}