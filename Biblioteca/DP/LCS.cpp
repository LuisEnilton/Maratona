#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5*1e3 + 5;
int memo[MAXN][MAXN];
// memo é a tabela que guarda o maior LCS possivel naquele estado da dp
// o estado é representado pela posição dos 2 ponteiros
// o i e o j são dois ponteiros um pra cada string
string s, t;

// A ideia do algoritmo é que não importa o que aconteceu antes, dado os dois indices eu tenho que calcular o LCS
 // só daquele estado,
 // o resultado final é feito combinando os subproblemas
 // Repara que ele começa no indice 0, mas ele vai ser o ultimo a ser calculado pq é recursivo


inline int LCS(int i, int j)
{
    // se algum dos ponteiros passou do tamanho da string n da de fzer mais nada retorna 0
    if(i == s.size() || j == t.size()) return 0;

    // Se esse caso já foi calculado retorna
    if(memo[i][j] != -1) return memo[i][j];

    //Se as duas letras forem iguais eu ando com os dois ponteiros ao msm tempo
    // eu somo 1 pq eu aumentei o tamanho da substring
    if(s[i] == t[j]) return memo[i][j] = 1 + LCS(i+1, j+1);
    // Se as duas letras não forem iguais eu tenho que testar
    // andar com as duas letras e pegar o maximo de cada uma
    return memo[i][j] = max(LCS(i+1, j), LCS(i, j+1));
}


inline int LCS_It()
{

    for(int i=s.size()-1; i>=0; i--)
        for(int j=t.size()-1; j>=0; j--)
        {
            if(s[i] == t[j])
                memo[i][j] = 1 + memo[i+1][j+1];
            else
                memo[i][j] = max( memo[i+1][j], memo[i][j+1] );
        }

    return memo[0][0];
}


inline string RecoverLCS(int i, int j)
{
    if(i == s.size() || j == t.size()) return "";

    if(s[i] == t[j]) return s[i] + RecoverLCS(i+1, j+1);

    if(memo[i+1][j] > memo[i][j+1]) return RecoverLCS(i+1, j);

    return RecoverLCS(i, j+1);
}


int main(){
    cin >> s >> t;

    cerr << "Max size: " << LCS_It() << endl;

    cout << RecoverLCS(0, 0) << endl;

    return 0;
}


/****************************

LCS - Longest Common Subsequence

Complexity: O(N^2)

* Recursive:
memset(memo, -1, sizeof memo);
LCS(0, 0);

* Iterative:
LCS_It();


* RecoverLCS
  Complexity: O(N)
  Recover one of all the possible longest 
  common subsequence.
  Return a String.

*****************************/