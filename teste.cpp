#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 100000010
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
#define MAXN 1000
#define MAXL 23
#define endl '\n'

using namespace std;

int matriz[MAXN][MAXN];
int n, m, res = 0;

void limpar(int line, int col){
    matriz[line][col] = 0;

    if(col > 0 && matriz[line][col-1] == 1) limpar(line, col-1);
    if(line > 0 && matriz[line-1][col] == 1) limpar(line-1, col);
    if(col < m-1 && matriz[line][col+1] == 1) limpar(line, col+1);
    if(line < n-1 && matriz[line+1][col] == 1) limpar(line+1, col);
}

void labt(int line, int col){

    if(matriz[line][col]){
        res++;
        limpar(line, col);
    }

<<<<<<< Updated upstream
int main(int argc, char const *argv[])
{
    
    cout << "hello world" << endl;
=======
    if(col == m-1){
        if(line == n-1) return;
        labt(line+1, 0);
    }else{
        labt(line, col+1);
    }
}

int main(int argc, char** argv)
{
    optimize;
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> matriz[i][j];
        }
    }

    labt(0, 0);

    cout << res << endl;

>>>>>>> Stashed changes
    return 0;
}
p