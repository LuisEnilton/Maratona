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
    int l,c; cin >> l >> c;
    vector<vs> grid(l, vs(c));    
    queue<int> q;
    map<string,set<int>> mp;
    for(int i = 0; i < l;i++){
        auto coisa = Coisa();
        coisa.id = sla;
        sla++;
        set<string> dif;
        for(int j = 0; j < c;j++){
            cin >> grid[i][j];
            coisa.cnt[grid[i][j]]++;
            dif.insert(grid[i][j]);
            mp[grid[i][j]].insert(coisa.id);
        }
        int sum; cin >> sum;
        coisa.val = sum;
        coisa.quant = dif.size();
        guarda.PB(coisa);
        if(dif.size() == 1) q.push(coisa.id);
    }

    vi val_cols(c);
    for(auto & x : val_cols) cin >> x;

    for(int j = 0; j < c;j++){
        auto coisa = Coisa();
        coisa.id = sla;
        sla++;
        set<string> dif;
        for(int i = 0; i < l;i++){
            coisa.cnt[grid[i][j]]++;
            dif.insert(grid[i][j]);
            mp[grid[i][j]].insert(coisa.id);
        }
        coisa.val = val_cols[j];
        coisa.quant = dif.size();
        guarda.PB(coisa);
        if(dif.size() == 1) q.push(coisa.id);
    }
    map<string,int> ans;

    // for(int i = 0; i < sla;i++){
    //     cout << i << " " << guarda[i].quant << endl;
    // }

    while(q.size()){
        int idx = q.front();
        auto coisa = guarda[idx]; q.pop();
        
        // cout <<"IDX: " << idx << endl;
        
        if(coisa.cnt.size() == 0) continue;

        auto [k,v] = *coisa.cnt.begin();
        // cout << k << " " << v << endl;
        int valor = coisa.val/v;
        // cout << valor << endl;
        ans[k] = valor;

        mp[k].erase(idx);

        
        for(auto id : mp[k]){
            auto &coi = guarda[id];
            coi.quant--;
            coi.val -= valor * coi.cnt[k];
            coi.cnt.erase(k);
            if(coi.quant == 1) q.push(id);
            // cout << id << " " << coi.quant << endl;
        }
        // cout << "==========" << endl;
    }

    for(auto [k,v] : ans){
        cout << k << " " << v << endl;
    }

    return 0;
}