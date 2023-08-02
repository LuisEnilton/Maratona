#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
using namespace std;

#define int long long

const int MOD = 1e9+9;
const int base = 153;

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

    StringHash(string& _s){
        hsh=vector<int>(_s.length()+1,0);
        for (int i=0;i<_s.length();i++){
            hsh[i+1]=((hsh[i]*base)%MOD + _s[i])%MOD;
        }
    }

    int get_value(int a,int b){
        return (MOD + hsh[b+1] - (hsh[a]*expBase[b-a+1])%MOD)%MOD;
    }
};



int32_t main(){
    precalc();
    string bin, t;
    cin >> bin >> t;


    StringHash hsh (t);


    int n = t.size(), m=bin.size();
    int tot1 = 0, tot0 = 0;
    int pos1 = -1, pos0 = -1;
    //O(m)
    for(int i=0; i<m; i++)
    {
        if(bin[i] == '0')
        {
            tot0++;

            if(pos0 == -1) pos0 = i;
        }
        else
        {
            tot1++;

            if(pos1 == -1) pos1 = i;
        }
    }


    int ans = 0;
    //O(n)
    for(int sz0=1, sz1; sz0*tot0 < n; sz0++)
    {
        if( (n - (sz0 * tot0) ) % tot1 != 0) continue;
        sz1 = ( n - (sz0 * tot0) ) / tot1;


        ll h1 = hsh.get_value( pos1*sz0, pos1*sz0 + sz1-1);
        ll h0 = hsh.get_value( pos0*sz1, pos0*sz1 + sz0-1);


        if(h1 == h0) continue;


        bool ok = true;

        for(int i=0, pos=0; i<m && ok; i++)
        {
            if(bin[i] == '0')
            {
                if( hsh.get_value(pos, pos+sz0-1) != h0 ) ok = false;

                pos += sz0;
            }
            else
            {
                if( hsh.get_value(pos, pos+sz1-1) != h1 ) ok = false;

                pos += sz1;
            }
        }


        if(ok) ans++;
    }

    cout << ans << endl;

    return 0;
}