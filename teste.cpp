#include <bits/stdc++.h>
using namespace std;
#include "LeetCode/198 - HouseRobber/Solution.h"







int main(int argc, char const *argv[])
{
    Solution sol = *new Solution();
    vi nums{2,7,9,3,1};
    cout <<sol.rob(nums) << endl;
    return 0;
}
