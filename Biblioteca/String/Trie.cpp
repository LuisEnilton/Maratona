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
cout.tie(NULL)
#define vi vector<int>
#define PB push_back
#define EB emplace_back
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;


// Trie
//
// trie T() constroi uma trie para o alfabeto das letras minusculas
// trie T(tamanho do alfabeto, menor caracter) tambem pode ser usado
//
// T.insert(s) - O(|s|*sigma)
// T.erase(s) - O(|s|)
// T.find(s) retorna a posicao, -1 se nao achar - O(|s|)
// T.count_pref(s) numero de strings que possuem s como prefixo - O(|s|)

struct Trie {
    vector<vi > to;
    vector<pair<int, char> > back;
    vector<pair<string, int> > ans;
    vi end, pref;
    int sigma;
    char norm;

    Trie(int sigma_ = 26, char norm_ = 'a') : sigma(sigma_), norm(norm_) {
        to = {vi(sigma)};
        end = {0}, pref = {0};
        back = {{-1, '*'}};
        ans = {{"", -1}};
    }

    void insert(string &s) {
        int x = 0;
        for (auto c: s) {
            int &nxt = to[x][c - norm];
            if (!nxt) {
                nxt = to.size();
                back.EB(x, c);
                to.PB(vi(sigma));
                end.PB(0), pref.PB(0);
            }
            x = nxt, pref[x]++;
        }

        end[x]++, pref[0]++;
    }


    void erase(string &s) {
        int x = 0;
        for (char c: s) {
            int &nxt = to[x][c - norm];
            x = nxt, pref[x]--;
            if (!pref[x]) nxt = 0;
        }
        end[x]--, pref[0]--;
    }

    int find(string &s) {
        int x = 0;
        for (auto c: s) {
            x = to[x][c - norm];
            if (!x) return -1;
        }
        return x;
    }

    int count_pref(string &s) {
        int id = find(s);
        return id >= 0 ? pref[id] : 0;
    }

};