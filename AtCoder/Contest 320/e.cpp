//
// Created by Luis on 16/09/2023.
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

typedef pair<pair<ll,ll>,pair<ll,ll>> Evento;



int main(int argc, char **argv) {
    // t1 : tipo : t,s
    //0 volta 1 jogar
    optimize;
    priority_queue<Evento, vector<Evento>, greater<>> events;
    int n, m;
    cin >> n >> m;
    bitset<200010> persons;
    persons.flip();
    vector<ll> food(n+1);
    while (m--) {
        ll t, w, s;
        cin >> t >> w >> s;
        Evento ev = {{t,1},{w,s}};
        events.push(ev);
    }

    while(!events.empty()){
        Evento ev = events.top();
        events.pop();
        if(ev.first.second == 1 ){
            int idx = persons._Find_first();
            if(idx >=n) continue;
            food[idx]+=ev.second.first;
            persons.reset(idx);
            Evento e = {{ev.first.first+ev.second.second,0},{idx,0}};
            events.push(e);
        }else{
            int idx = ev.second.first;
            persons.set(idx);
        }
    }

    for(int i = 0; i < n;i++){
        cout << food[i] << endl;
    }

    return 0;
}

