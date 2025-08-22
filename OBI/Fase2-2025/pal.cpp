//
// Created by Luis on 06/09/2023.
//
// Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>
#define BT bitset<500>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define MAXN 400010
#define int ll
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>


struct Coisa{
    int id;
    int quant; // quantidade de variaveis
    int val; // valor que falta;
    map<string,int> cnt;
    Coisa(int i,int q,int v){
        this->id = i;
        this->quant = q;
        this->val = v;
    }

    Coisa(){};

    bool operator<(const Coisa &c){
        return this->id < c.id;
    }

};

int sla = 0;

vector<Coisa> guarda;

signed main()
{
    optimize;
    int n; cin >> n;
    vi a(n);
    for(auto & x : a) cin >> x;

    int l = 0, r = n - 1;
    int ans = 0;
    while(l < r){
        //cout << l << " " << r << endl;
        if(a[l] == a[r]){
            l++;
            r--;
            continue;
        }

        if(a[l] > a[r]){
            a[r - 1] += a[r];
            ans++;
            r--;
            continue;
        }
        
        if(a[l] < a[r]){
            a[l + 1] += a[l];
            ans++;
            l++;
            continue;
        }

    }
    cout << ans << endl;

    return 0;
}