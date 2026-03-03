#include <bits/stdc++.h>

#define INFLL 1000000000000000010LL
#define ll long long
#define int ll
#define vi vector<int>


using namespace std;

const int MOD = 1e9 + 7;
struct Matrix
{
    vector<vi> mat;
    int n, m;
    Matrix(int N, int M = 0) : n(N), m(M ? M : N)
    {
        mat.resize(n);
        for (int i = 0; i < n; i++)
            mat[i].resize(m, 0);
    }

    friend Matrix operator*(const Matrix &a, const Matrix &b)
        {
            assert(a.m == b.n);
            Matrix ans = Matrix(a.n, b.m);
            for (int i = 0; i < a.n; i++)
                for (int j = 0; j < b.m; j++){
                    int sum = 0;
                    for (int k = 0; k < a.m; k++)
                        sum +=  ((a.mat[i][k] * b.mat[k][j]) % MOD);
                    ans.mat[i][j] = sum % MOD;
                }
            return ans;
        }

    void printMat()
    {
        for (auto &linha : mat)
        {
            for (auto &cel : linha)
            {
                cout << cel << " ";
            }
            cout << endl;
        }
    }
};

Matrix fexp(Matrix a, ll exp)
{
    assert(a.n == a.m);
    int m = a.m;
    Matrix ans = Matrix(m);
    for (int i = 0; i < m; i++)
        ans.mat[i][i] = 1;
    while (exp)
    {
        if (exp & 1)
            ans = ans * a;
        a = a * a;
        exp >>= 1;
    }
    return ans;
}