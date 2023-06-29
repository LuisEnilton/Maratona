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

int N;
vector<string> linhas;

int main(int argc, char const *argv[]) {
    optimize;
    cin >> N;
    cin.ignore();

    linhas.resize(N);
    string linha;

    for(auto &x:linhas){
        getline(cin,linha);
        linhas.PB(linha);
    }

    stack<char> chaves;

    for(auto line:linhas){

        for(auto c : line){
            if(c=='{' || c == '}')
                chaves.push(c);
        }
    }
    int count_abre = 0;
    int count_fecha = 0;
    bool ans = true;

    while(!chaves.empty()){
        char ch = chaves.top();

        if(ch == '{')
            count_abre++;
        else
            count_fecha++;


        if(count_abre> count_fecha)
            ans = false;

        chaves.pop();
    }

    if(count_abre!= count_fecha) ans = false;

    if(ans)
        cout<<"S"<<endl;
    else
        cout<<"N"<<endl;
    return 0;
}



