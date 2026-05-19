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
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define int ll
#define dbg(x) cout << #x << " " << x << endl;
// #define endl '\n'
#define print_arr(a)      \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl;
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

void solve()
{
    map<string, int> id =
        {
            {"Mon", 0},
            {"Tue", 1},
            {"Wed", 2},
            {"Thu", 3},
            {"Fri", 4},
            {"Sat", 5},
            {"Sun", 6}};

    auto cast = [&](string & s){
        int curr = 0;
        curr = (s[0] - '0') * 10 + (s[1] - '0');

        curr *= 60;

        curr += (s[3] - '0') * 10 + (s[4] - '0');
        return curr;
    };     

    string dia1,hora1; cin >> dia1 >> hora1;        
    string dia2,hora2; cin >> dia2 >> hora2;        

    if(dia1 == dia2 && hora1 == hora2){
        cout << "7 days" << endl;
        return;
    }

    int ans_dia;
    int id_1 = id[dia1], id_2 = id[dia2];
    // dbg(id_1);        
    // dbg(id_2);        
    if(id_1 > id_2){
        ans_dia = (7 - id_1) + id_2;
    }else{
        ans_dia = id_2 - id_1;
    }

    int m1 = cast(hora1);
    int m2 = cast(hora2);
    // dbg(m1);
    // dbg(m2);
    int tot_m = 24 * 60;
    int ans_m;
    if(hora1 > hora2){
        ans_dia--;
        if(ans_dia == -1) ans_dia = 6; // deu a volta
        ans_m = (tot_m - m1) + m2;
    }else{
        ans_m = m2 - m1;
    }
    // dbg(ans_dia);
    // dbg(ans_m);
    int q_h = 0;
    while(ans_m >= 60){
        q_h++;
        ans_m -= 60;
    }
    // dbg(q_h);
    // dbg(ans_m);

    vector<pii> comp;
    if(ans_dia > 0) comp.emplace_back(0,ans_dia);
    if(q_h > 0) comp.emplace_back(1,q_h);
    if(ans_m > 0) comp.emplace_back(2,ans_m);

    auto print_coisa = [&](pii sla){
        if(sla.first == 0){
            cout << sla.second << " day" << (sla.second > 1 ? "s":"");
        }
        if(sla.first == 1){
            cout << sla.second << " hour" << (sla.second > 1 ? "s":"");
        }
        if(sla.first == 2){
            cout << sla.second << " minute" << (sla.second > 1 ? "s":"");
        }
    };


    if(comp.size() == 1){
        print_coisa(comp.back());
    }else if(comp.size() == 2){
        print_coisa(comp[0]);
        cout << " and ";
        print_coisa(comp[1]);
    }else{
        print_coisa(comp[0]);
        cout << ", ";
        print_coisa(comp[1]);
        cout << ", ";
        print_coisa(comp[2]);
    }
    cout << endl;


}

signed main()
{
    optimize;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
