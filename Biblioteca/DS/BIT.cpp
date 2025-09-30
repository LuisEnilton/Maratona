#include <bits/stdc++.h>
using namespace std;
#define LOGN 24
struct BIT {
	int N;
	vector<int> bit;

	BIT(){}
	BIT(int n) : N(n+1), bit(n+1){}

	void update(int pos, int val){
		for(; pos < N; pos += pos&(-pos))
			bit[pos] += val;
	}

	int query(int pos){
		int sum = 0;
		for(; pos > 0; pos -= pos&(-pos))
			sum += bit[pos];
		return sum;
	}

	 // primeira posição em que ps >= v
    int lb(int v)
    {
        int sum = 0;
        int pos = 0;

        for (int i = LOGN; i >= 0; i--)
        {
            if (pos + (1 << i) < N && sum + bit[pos + (1 << i)] < v)
            {
                sum += bit[pos + (1 << i)];
                pos += (1 << i);
            }
        }

        return pos + 1; // +1 because 'pos' will have position of largest value less than 'v'
    }

};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
}