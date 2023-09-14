//
// Created by Luis on 14/09/2023.
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

int dy[8] = {-1,-1,-1,0,0,1,1,1};
int dx[8] = {-1,0,1,1,-1,-1,0,1};
/*
 1 2 3
 5 A 4
 6 7 8
  */
const int maxn = 1001;
int grid[maxn][maxn];
vector<vector<bool>> picos(maxn,vector<bool>(maxn,true));
vector<vector<bool>> visitado(maxn,vector<bool>(maxn,false));
int cnt = 0,n,m;

bool check(int y , int x){
    if(x < 0 || y < 0 || y >=n || x>=m){
        return false;
    }
    return true;
}

void dfs(int y = 0, int x = 0){
    queue<pii > fila;
    fila.emplace(y,x);
    while(!fila.empty()){
        auto atual = fila.front();
        fila.pop();
        int Y = atual.first;
        int X = atual.second;
        if(!picos[Y][X]) continue;
        if(visitado[Y][X]) continue;
        visitado[Y][X] = true;
        for(int j = 0; j < 8;j++){
            int _y = Y + dy[j];
            int _x = X + dx[j];
            if(check(_y,_x)){
                if(grid[Y][X] <= grid[_y][_x]){
                    picos[Y][X] = false;
                }else{
                    picos[_y][_x] = false;
                }
                fila.emplace(_y,_x);
            }

        }
        if(picos[Y][X]){
            cout << Y + 1 << " " <<X + 1 << endl;
            cnt++;
        }
    }


}



int main(int argc, char** argv)
{
    cin >> n >> m;
    cnt = 0;
    for(int i =0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> grid[i][j];
        }
    }
    dfs();
    cout << cnt << endl;
    return 0;
}

