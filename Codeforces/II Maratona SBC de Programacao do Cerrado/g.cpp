//
// Created by Luis on 06/09/2023.
//
// Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define BT bitset<500>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define MAXN 1000010
#define int ll
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

void solve()
{
    string l1;

    getline(cin, l1);

    auto solve_print = [&](string line)
    {
        auto idx = line.find("(") + 1;
        string coisa = "";
        char fech;
        if(line[idx] == '\"'){
            fech = '\"';
            coisa += line[idx++];
        }else if(line[idx] == '\''){
            fech = '\'';
            coisa += line[idx++];
        }else{
            fech = ')';
        }
        // dbg(fech);
        for (; idx < line.size(); idx++)
        {
            coisa += line[idx];
            if (line[idx] == fech)
                break;
        }
        if(coisa.back() == ')') coisa.pop_back();
        cout << "APRESENTE " << coisa << endl;
    };

    auto solve_input = [&](string line)
    {
        string coisa;
        int idx = line.find('=') - 2;
        for (; idx >= 0 && line[idx] != ' '; idx--)
        {
            coisa += line[idx];
        }
        reverse(ALL(coisa));
        cout << "LEIA " << coisa << endl;
    };
    if (l1.substr(0,6) == "print(")
    {
        solve_print(l1);
        return;
    }

    if (l1.substr(0,3) == "if ")
    {
        string cond;
        for (int idx = 3; l1[idx] != ':'; idx++)
        {
            cond += l1[idx];
        }
        string l2;
        getline(cin, l2);

        cout << "SE " << cond << " ENTAO ";
        // dbg(l2);
        int idx2 = 0;
        for(; l2[idx2] == ' ';idx2++);
        
        l2 = l2.substr(idx2);
        if (l2.substr(0,6) == "print(")
        {
            solve_print(l2);
        }
        else
        {
            solve_input(l2);
        }
        return;
    }
    // dbg(l1.substr(0,6));
    if (l1.substr(0,6) == "while ")
    {
        string cond = "";
        int idx = l1.find("while") + 6;
        for (; l1[idx] != ':'; idx++)
        {
            cond += l1[idx];
        }
        string l2;
        getline(cin, l2);
        //  dbg(l2);
        cout << "ENQUANTO " << cond << " ";


        int idx2 = 0;
        for(; l2[idx2] == ' ';idx2++);
        
        l2 = l2.substr(idx2);

        if (l2.substr(0,6) == "print(")
        {
            solve_print(l2);
        }
        else
        {
            solve_input(l2);
        }
        return;
    }

    solve_input(l1);
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
