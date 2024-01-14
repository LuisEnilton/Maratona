//
// Created by Luis on 06/01/2024.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cmath>

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

char Dir(char d) {
    if (d == 'd') return 'b';
    if (d == 'b') return 'e';
    if (d == 'e') return 'c';
    if (d == 'c') return 'd';
}

int n;
vector<vector<string>> grid;
bool check(int x, int y) {
    if ((x == 0 || x == n - 1) && (y == 0 || y == n - 1)) return true;
    return false;
}

int main() {
    optimize;

    cin >> n;
    grid = vector<vector<string>>(n, vector<string>(n));
    grid[n / 2][n / 2] = 'T';
    int i = 1;
    char d = 'd';
    int y = 0, x = 0;
    while (i <= n * n - 1) {
        grid[y][x] = to_string(i);
        if(i == n * n - 1) break;
        if (check(x, y) && i > 1) {
            d = Dir(d);
        }
        if (d == 'd') {
            if(grid[y][x + 1] != ""){
                d = Dir(d);
                continue;
            }else{
                x++;
            }
        }
        if (d == 'e') {
            if(grid[y][x - 1] != ""){
                d = Dir(d);
                continue;
            }else{
                x--;
            }
        }

        if (d == 'c') {
            if(grid[y-1][x] != ""){
                d = Dir(d);
                continue;
            }else{
                y--;
            }
        }

        if (d == 'b') {
            if(grid[y + 1][x] != ""){
                d = Dir(d);
                continue;
            }else{
                y++;
            }
        }
        i++;
    }
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            cout << grid[j][k] << " ";
        }
        cout << endl;
    }
    return 0;
}

