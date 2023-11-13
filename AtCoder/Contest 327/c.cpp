//
// Created by Luis on 04/11/2023.
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


int grid[9][9];



int main() {
    optimize;
    bool ok = true;
    for (auto & i : grid) {
        for (int & j : i) {
            cin >> j;
        }
    }
    //teste linhas;
    for (int i = 0; i < 9; i++) {
        bitset<10> aux;
        for (int j = 0; j < 9; j++) {
            if(aux.test(grid[i][j])){
                ok = false;
                break;
            }
            aux.set(grid[i][j]);
        }
    }
    if(!ok) {
        cout << "No" << endl;
        return 0;
    }
    for (int j = 0; j < 9; j++) {
        bitset<10> aux;
        for (int i = 0; i < 9; i++) {
            if(aux.test(grid[i][j])){
                ok = false;
                break;
            }
            aux.set(grid[i][j]);
        }
    }
    if(!ok) {
        cout << "No" << endl;
        return 0;
    }
    for(int vert = 0; vert < 3;vert++){
        for(int hor = 0;hor < 3;hor++){
            bitset<10> aux;
            for(int i = vert * 3;i < (3*vert) + 3;i++){
                for(int j = hor *3;j < (3*hor) + 3;j++){
                    if(aux.test(grid[i][j])){
                        ok = false;
                        break;
                    }
                    aux.set(grid[i][j]);
                }
                }
            }
        }
    if(!ok) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}

/*

1 2 3 4 5 6 7 8 9
4 5 6 7 8 9 1 2 3
7 8 9 1 2 3 4 5 6
2 3 4 5 6 7 8 9 1
5 6 7 8 9 1 2 3 4
8 9 1 2 3 4 5 6 7
3 4 5 6 7 8 9 1 2
6 7 8 9 1 2 1 4 5
9 1 2 3 4 5 6 7 8



 * */