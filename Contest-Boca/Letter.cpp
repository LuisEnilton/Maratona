#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <string>
#include <algorithm>
#include <set>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 100000010
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<char,int >
#define vi vector<int>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101
#define MAXN 101010
#define MAX_MOEDAS 1010
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;

int N;

map<int,map<char,int>> letras;





int main() {
    optimize;
    cin >>N;
    pii p;
    map<int,int> m;
    while(N--){
    string s;
    cin >>s;
    cin.ignore();
    int i =1;
    for(char c: s){
        letras[{i}][{c}]+=1;
        i++;
    }
    }
    int i=1;
    for(auto &map : letras){
        int max =0;
        for(auto &l :map.second){
            if(l.second>max) max = l.second;

        }
        printf("%d: ",i);
        for(auto &l :map.second){
            if(l.second ==max) printf("%c ",l.first);
        }
        if(i<letras.size()) printf("\n");
        i++;
    }
}
