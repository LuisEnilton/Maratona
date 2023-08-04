//
// Created by Luis on 03/08/2023.
//

#ifndef MARATONA_MINSTACK_H
#define MARATONA_MINSTACK_H
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
//#define INF 1000000010
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
const int INF = 2e31 -1;
class MinStack {
        public:
        stack<int> pilha;
        stack<int> min;
        MinStack() {
             pilha = stack<int>();
             min = stack<int>();
             min.push(INF);
        }

        void push(int val) {
            pilha.push(val);
            if(val < min.top()) min.push(val);
        }

        void pop() {

            if(pilha.top() == min.top()) min.pop();
            pilha.pop();
        }

        int top() {
            return pilha.top();
        }

        int getMin() {
            return min.top();
        }
};


#endif //MARATONA_MINSTACK_H
