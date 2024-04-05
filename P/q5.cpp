//
// Created by Luis on 05/03/2024.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cmath>

#define endl '\n'

using namespace std;
// n é o numero que se deseja encontrar na sequência
void inverterString(string &s){
    int n = s.size();
    for(int i = 0; i < n/2;i++){
        char aux;
        aux = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = aux;
    }
}


int main() {
    string s = "abcd";
    inverterString(s);
    cout << s << endl;

    s = "abcde";
    inverterString(s);
    cout << s<< endl;
    return 0;
}



