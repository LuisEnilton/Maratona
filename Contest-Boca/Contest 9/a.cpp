#include <bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
#define ALL(x) x.begin(),x.end()
#define vi vector<int>
#define endl '\n'

using namespace std;
int h,k,v,s;

int main(int argc, char const *argv[])
{
    cin >> h >> k >> v >> s;
    int d =0;
    while(h > 0){
        v+=s;
        v = v- max(1,v/10);
        if(v>=k)h++;
        if(v > 0 && v < k){
            h--;
            if(h == 0) v =0;
        }
        if(v <=0){
            h=0;
            v=0;
        }
        d+=v;
        if(s>0) s--;
    }
    cout << d << endl;
    return 0;
}
