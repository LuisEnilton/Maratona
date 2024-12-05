//
// Created by Luis on 20/07/2023.
//
#include <bits/stdc++.h>
using namespace std;
#define int ll
typedef long long ll;
const int MAXN = 2e5 + 5;

int bit[MAXN];
int arr[MAXN];

void upd(int x, int v){
  // 1 Indexado
  while(x < MAXN){
        bit[x] += v;
        x += (x & -x);
    }
}

int qry(int x){
    ll ret = 0;

    while(x > 0){
        ret += bit[x];
        x -= (x & -x);
    }
    return ret;
}

signed main(){
     int n,q ; cin >> n >> q;

     for(int


}