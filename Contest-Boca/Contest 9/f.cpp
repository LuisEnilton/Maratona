#include <bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ALL(x) x.begin(),x.end()
#define vi vector<int>
#define endl '\n'
//#define INF 100000010;
using namespace std;
int n ,d;
stack<int> visita;
vi limpe,suja;
const int INF = 100000010;

int solve(){
  int ans = 0;
    while(visita.top() != -1){
      int dia = visita.top();
      visita.pop();
      int limpeza = limpe[dia];
      int sujeira = suja[dia];
      if(limpeza < sujeira)
          return -1;
      else{
          limpeza-=sujeira;
          ans++;
          int i = dia - 1;
          priority_queue<int> pq;
          pq.push(limpe[i]);
          while(i != visita.top() && i >= 0){

              if(limpeza >= suja[i]){
                  limpeza-=suja[i];
                  pq.push(limpe[i]);
                  i--;
              }else{
                  if(pq.empty()) return -1;
                  suja[i]-=limpeza;
                  limpeza = pq.top();
                  pq.pop();
                  ans++;
              }
          }
      }


  }
    return ans;

}
int main(int argc, char const *argv[])
{
    optimize;
    cin >> n >> d;
    limpe.resize(n);
    suja.resize(n);

    //for(auto x : visita) cerr << x << endl;
    for(int i =0;i < n;i++){
        cin >> suja[i];
        cin >> limpe[i];
    }
    visita.push(-1);
    while(d--){
        int v;
        cin >> v;
        visita.push(v - 1);
    }
    cout << solve() << endl;
    //for(auto x : dp){
    //    cout <<  "i: "<<x.first.first << " sujeira: " << x.first.second << " valor: " << x.second << endl;
    //}
    return 0;
}

