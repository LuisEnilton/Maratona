#include <bits/stdc++.h>
using namespace std;
int rnd(int a, int b)
{
    return a + rand() % (b - a + 1);
}
int main(int argc, char *argv[])
{
    int seed = atoi(argv[1]);
    srand(seed);

    for(int i = 0 ; i < 4;i++){
        int n = rnd(1, 5);
        cout << n << endl;
        for(int j = 0 ; j < n;j++){
            int x = rnd(1,10);
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
}