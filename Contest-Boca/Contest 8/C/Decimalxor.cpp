#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 100000010
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int,int>
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

int main() {
    optimize;
    int num1, num2;
    cin >> num1 >> num2;

    int max_digitos = max(to_string(num1).length(), to_string(num2).length());
    string str_num1 = to_string(num1);
    string str_num2 = to_string(num2);
    str_num1 = string(max_digitos - str_num1.length(), '0') + str_num1;
    str_num2 = string(max_digitos - str_num2.length(), '0') + str_num2;

    string resultado = "";

    for (int i = max_digitos - 1; i >= 0; --i) {
        int digito1 = str_num1[i] - '0';
        int digito2 = str_num2[i] - '0';

        int dexor = ((digito1 <= 2 && digito2 <= 2) || (digito1 >= 7 && digito2 >= 7)) ? 0 : 9;

        resultado = to_string(dexor) + resultado;
    }

    cout << resultado << endl;

    return 0;
}
