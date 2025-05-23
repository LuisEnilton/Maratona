#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 1000000010
#define INFLL 1000000000000000010LL
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
#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'
#define int ll
using namespace std;
using namespace __gnu_pbds;
 
#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>
 
int n, k;
 
struct Element {
    int val, gc;
 
    Element(int val, int gc) {
        this->val = val;
        this->gc = gc;
    }
};
 
struct MinStack {
    stack<Element> pilha;
 
    void push(int x) {
        if (pilha.empty()) {
            pilha.emplace(x, x);
            return;
        }
        auto [y,gc] = this->pilha.top();
        pilha.emplace(x, gcd(x, gc));
    }
 
    void pop() {
        if (pilha.empty()) return;
        pilha.pop();
    }
 
    int curr() {
        if (pilha.empty()) return 0;
        return pilha.top().gc;
    }
 
 
    bool empty() {
        return pilha.empty();
    }
 
    Element top() {
        return pilha.top();
    }
 
    int size() {
        return pilha.size();
    }
};
 
struct MinQueue {
    MinStack s1, s2;
 
    int curr() {
        if (s1.empty() && s2.empty()) return 0;
        if (s1.empty()) return s2.top().gc;
        if (s2.empty()) return s1.top().gc;
        return gcd(s1.top().gc, s2.top().gc);
    }
 
 
    void push(int x) {
        s2.push(x);
    }
 
    void pop() {
        if (s1.empty()) {
            while (!s2.empty()) {
                auto e = s2.top();
                s2.pop();
                s1.push(e.val);
            }
        }
        s1.pop();
    }
 
};