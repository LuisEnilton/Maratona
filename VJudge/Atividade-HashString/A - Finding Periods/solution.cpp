#include<bits/stdc++.h>

using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const int MOD=1e9+9;//big prime number
const int base=153;//random number larger than the size of the alphabet

const int maxn=1e6+10;
int expBase[maxn];

void precalc(){
    expBase[0]=1;
    for (int i=1;i<maxn;i++){
        expBase[i]=(expBase[i-1]*base)%MOD;
    }
}

struct StringHash{
    vector<int> hsh;
    //REMEMBER TO RUN PRECALC
    StringHash(string& _s){
        hsh=vector<int>(_s.length()+1,0);
        for (int i=0;i<_s.length();i++){
            hsh[i+1]=((hsh[i]*base)%MOD + _s[i])%MOD;
        }
    }

    //interval =  [a,b] closed
    int get_value(int a,int b){
        return (MOD + hsh[b+1] - (hsh[a]*expBase[b-a+1])%MOD)%MOD;
    }


};


int n;

bool solve(StringHash &hash,int x ){
    int pref = hash.get_value(0,x-1);

    for(int i =0;i < n;i += x){
        if(i+x-1 >= n){
            int falta = n-i;
            if(hash.get_value(0,falta-1)!= hash.get_value(i,i+falta - 1))
                return false;
        }else{
            if(pref != hash.get_value(i,x+ i -1))
                return false;
        }
    }
    return true;
}


signed main(){
    optimize;
    precalc();
    string s;
    cin >> s;
    StringHash hash(s);
    n = s.size();


    vector<int> resposta;
    for(int i = 1;i <= s.size();i++){
        if(solve(hash,i))
            resposta.push_back(i);
    }

    for(auto k : resposta){
        cout << k << " ";
    }
    cout <<"\n";
    return 0;

}