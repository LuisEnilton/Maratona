//
// Created by Luis on 14/07/2023.
//

#include "Solution.h"

int main(int argc, char** argv)
{
    optimize;
    Solution sol = *new Solution();
    vector<int> nums{10,15,25};
    cout << sol.minCostClimbingStairs(nums);



    return 0;
}