//
// Created by Luis on 23/10/2023.
//
//
// Created by Luis on 23/10/2023.
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


//Estrutura de Dados para mannter os dados em blocos sqrt
struct sqrt_decomp{
    //0-INDEXADO!!!!
    const static int maxn = 2e5+10;// maxn
    const static int magic= 450;//Aproximadamente sqrt(maxn)
    ll sqr[magic];
    ll arr[maxn];

    //Construtor para decompor o vetor na estrutura
    sqrt_decomp(vector<ll>&v){
        int n=v.size();
        for (int i=0;i<n;i++)arr[i]=v[i];
        for (int i=0;i<n;i++){
            sqr[i/magic]+=arr[i];
        }
    }
    //muda o ponto a para o valor  v
    void update(int a,ll v){
        sqr[a/magic]-=arr[a];
        arr[a]=v;
        sqr[a/magic]+=arr[a];
    }

    //retorna o valor de  [0,t]
    ll query(int t){
        ll total=0;
        // se eu conseguir pegar o bloco completo, eu pego
        for (int i=0;i<t/magic;i++){
            total+=sqr[i];
        }
        //o ultimo bloco eu entro e pego o que eu preciso
        for (int i=(t/magic)*magic;i<=t;i++)total+=arr[i];
        return total;
    }

    //Retorna o valor de  [a,b];
    ll query(int a,int b){
        if (a==0) return query(b);
        return query(b)-query(a-1);
    }

};


int main()
{
    optimize;
    int n,q;
    cin >> n >> q;
    vector<ll> nums(n);
    for(auto &x: nums) cin >> x;
    auto decompoton = *new sqrt_decomp(nums);
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int k,u; cin >> k >> u;
            k--;
            decompoton.update(k,u);
        }else{
            int l,r;
            cin >> l >> r;
            l--,r--;
            cout << decompoton.query(l,r)<<endl;
        }
    }
    return 0;
}

