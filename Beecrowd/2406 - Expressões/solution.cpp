//
// Created by Luis on 29/06/2023.
//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <string>
#include <vector>
#include <iostream>
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
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101
#define MAXN 101010
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

int T;
vector<string> linhas;

bool comparar_chave(char c,stack<char> prox_sair){
    bool resp = false;
    char prox = prox_sair.top();
    if(c == '{' && prox == '}')
        resp = true;
    if(c == '[' && prox == ']')
        resp = true;
    if(c == '(' && prox == ')')
        resp = true;
    return resp;
}



int main(int argc, char const *argv[]) {
    optimize;
    cin >> T;
    cin.ignore();
    linhas.resize(T);
    string linha;
    for(auto &x:linhas){
        getline(cin,linha);
        linhas.PB(linha);
    }

    for(int i = 0;i < T ; i++){
        stack<char> chaves;

        for (auto c: linhas[i])
            chaves.push(c);

        int count_abre = 0;
        int count_fecha = 0;
        stack<char> prox_fechar;
        bool ok = true;


        while (!chaves.empty()) {
            char ch = chaves.top();
            if (ch == '{' || ch == '[' || ch == '(') {
                count_abre++;
                if (!comparar_chave(ch,prox_fechar) || prox_fechar.size() == 0) {
                    ok = false;
                } else
                    prox_fechar.pop();
            } else {
                count_fecha++;
                prox_fechar.push(ch);
            }
            chaves.pop();
        }

        if (count_abre != count_fecha)
            ok = false;
        if (ok)
            cout << "S" << endl;
        else
            cout << "N" << endl;
    }


    return 0;
}






