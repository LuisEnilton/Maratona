//
// Created by luise on 23/10/2023.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>
#include <iostream>
#include <ranges>
#include <string_view>
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
int m;
const int maxn = 1001;
char grid[maxn][maxn];

int cnt = 0;

bool check(int y,int x){
    if(y < 0 || x < 0 || y>=m || x >=m) return false;
    return true;
}

void saltar(int &y,int &x){
    char l = grid[y][x];
    grid[y][x] = '#';
    if(l == 'N'){
        y--;
    }
    if(l == 'S'){
        y++;
    }
    if(l == 'L'){
        x++;
    }
    if(l == 'O'){
        x--;
    }
    return;
}

void solve(int a,int b){
    int y = a;
    int x = b;
    while(true){
        if(!check(y,x)){
            cout << -1 << endl;
            return;
        }

        if(grid[y][x] == '#'){
            cout << 0 << endl;
            return;
        }

        if(grid[y][x] == 'X'){
            cout << cnt << endl;
            return;
        }
        saltar(y,x);
        cnt++;
    }
}

int main()
{
    optimize;
    cin >> m;
    for(int i =0; i < m;i++){
        for(int j = 0; j < m;j++){
            cin >> grid[i][j];;
        }
    }
        int a,b; cin >> a >> b;
        a--,b--;
        solve(a,b);
    return 0;
}

