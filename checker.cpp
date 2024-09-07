#include <bits/stdc++.h>
#define pb push_back
using namespace std;
vector<vector<int>> cl;

int calc(vector<int> &idx)
{
    int maxi = 0;
    int mini = 1e9;

    for (int i = 0; i < 4; i++)
    {
        maxi = max(cl[i][idx[i]], maxi);
        mini = min(cl[i][idx[i]], mini);
    }

    return maxi - mini;
}

int readAns(ifstream &fin)
{
    vector<int> idx(4);
    for(auto &x : idx) fin >> x;

    auto sum = calc(idx);
    
    return sum;
    
}
int main(int argc, char *argv[])
{
    ifstream fin("input_file", ifstream::in);
    ifstream ans("myAnswer", ifstream::in);
    ifstream cor("correctAnswer", ifstream::in);
    for (int i = 0; i < 4; i++){
        int n; fin >> n;
        vector<int> aux(n);
        for(auto &x : aux) fin >> x;
        sort(aux.begin(), aux.end());
        cl.push_back(aux);
    }
    int myAnswer = readAns(ans);
    int correctAnswer = readAns(cor);
    if (myAnswer != correctAnswer)
    {
        cout << "different" << " " << correctAnswer << " " << myAnswer << endl;
        return -1;
    }
    return 0;
}