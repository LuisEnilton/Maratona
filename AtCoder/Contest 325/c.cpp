//
// Created by Luis on 21/10/2023.
//
//
// Created by luise on 15/09/2023.
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

const int maxn = 1001;
char grid[maxn][maxn];
int dy[8] = {-1,-1,-1,0,0,1,1,1};
int dx[8] = {-1,0,1,1,-1,-1,0,1};
int n,m;
int cnt = 0;
/*
 1 2 3
 5 A 4
 6 7 8
  */

bool check(int y , int x){
    if(y < 0 || x < 0 || y >= n || x >=m) return false;
    return true;
}

void dfs(pii origem){
    cnt++;
    queue<pii> fila;
    fila.push(origem);

    while(!fila.empty()){
        auto [y,x] = fila.front();
        fila.pop();

        if(grid[y][x] == '.') continue;
        grid[y][x] = '.';
        for(int i = 0; i < 8;i++){
            int _y = y + dy[i];
            int _x = x + dx[i];
            if(check(_y,_x)){
                fila.push({_y,_x});
            }
        }
    }
}
void solve(){
    for(int i = 0 ; i < n;i++){
        for(int j = 0; j < m;j++){
            if(grid[i][j] == '.') continue;
            dfs({i,j});
        }
    }
}


int main(int argc, char** argv)
{
    optimize;
    cin >> n >> m;
    for(int i = 0 ; i < n;i++){
        for(int j = 0; j < m;j++){
            cin >> grid[i][j];
        }
    }
    solve();
    cout << cnt << endl;
    return 0;
}

