//
// Created by Luis on 12/07/2023.
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

int n;
priority_queue<int,vi> fila2;
queue<int> fila;
stack<int> pilha;
int main(int argc, char** argv)
{
    optimize;
    while((cin >> n) ) {
        vector<bool> ed(3, true);
        while (n--) {

            int op, x;
            cin >> op >> x;
            if (op == 1) {
                fila2.push(x);
                pilha.push(x);
                fila.push(x);
            } else {
                if (fila2.top() == x) {
                    fila2.pop();
                } else {
                    ed[2] = false;
                }

                if (fila.front() == x) {
                    fila.pop();
                } else {
                    ed[1] = false;
                }

                if (pilha.top() == x) {
                    pilha.pop();
                } else {
                    ed[0] = false;
                }
            }


        }
        vi nums;
        vector<string> esd{"stack", "queue", "priority queue"};
        int i = 0;
        for (bool ok: ed) {
            if (ok) nums.EB(i);
            i++;
        }
        if (nums.size() == 0) {
            cout << "impossible" << endl;
            continue;
        }

        if (nums.size() > 1) {
            cout << "not sure" << endl;
            continue;
        }
        cout << esd[nums[0]] << endl;
    }

    return 0;
}