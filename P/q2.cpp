//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cmath>

#define endl '\n'

using namespace std;
// n é o numero que se deseja encontrar na sequência
bool fib(int n){
    if(n == 0) return true;
    int a1,a2,a3 = 0;
    a1 = 0,a2 = 1;
    while(a3 <= n){
        a3 = a1 + a2;
        if(a3 == n) return true;
        a1 = a2;
        a2 = a3;
    }
    return false;
}


int main() {
    int n = 2;
    bool ans = fib(n);
    //cout << ans << endl;
    if(ans){
        cout << "Numero encontrado" << endl;
    }else{
        cout << "Numero nao encontrado" << endl;
    }

    return 0;
}



