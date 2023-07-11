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





int main(int argc, char const *argv[]) {
    optimize;
    cin >> T;
    stack<char> pilha;


    for(int i = 1;i <= T ; i++){
        while(!pilha.empty())
            pilha.pop();
        string s;
        cin >> s;
        bool ans = true;
        for (auto c: s){
            if(c == '{' || c == '[' || c == '(' ){
                pilha.push(c);
            }else{

                if(pilha.empty()){
                    ans = false;
                    break;
                }

                if(pilha.top() == '(' && c != ')')
                    ans = false;
                else if(pilha.top() == '[' && c != ']')
                    ans = false;
                else if(pilha.top() == '{' && c != '}')
                    ans = false;
                else
                    pilha.pop();
            }
        }
        if(pilha.size()> 0) ans = false;
        cout << (ans ? "S" : "N" ) << endl;
    }


    return 0;
}






