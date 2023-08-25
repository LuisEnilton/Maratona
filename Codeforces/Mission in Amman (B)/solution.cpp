//
// Created by Luis on 23/08/2023.
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

int u = 0 ;
int m;
struct number{
    int val;
    int id;
    number(int i){
        this->val = i;
        this->id = u++;
    }

    bool operator<(const number n)const{
        return val < n.val;
    }

    bool operator>(const number& n) const {
        return val > n.val;
    }

    void soma(int x){
        this->val+=x;
    }
};



int main(int argc, char** argv)
{
    priority_queue<number> pq1;
    priority_queue<number, vector<number>, greater<number>> pq2;

    cin >> m;
    for (int i = 0; i < m; ++i) {
        auto *a = new number(i); // Create a new instance of number
        pq1.push(*a);
        pq2.push(*a);
    }
    auto x = pq1.top();
    x.soma(3);
    return 0;
}

