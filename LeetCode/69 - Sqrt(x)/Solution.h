//
// Created by Luis on 29/07/2023.
//

#ifndef MARATONA_SOLUTION_H
#define MARATONA_SOLUTION_H


class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return x;
        int first = 1, last = x;
        while (first <= last) {
            int mid = first + (last - first) / 2;
            // mid * mid == x gives runtime error
            if (mid  == x / mid)
                return mid;
            else if (mid > x / mid) {
                last = mid - 1;
            }
            else {
                first = mid + 1;
            }
        }
        return last;
    }
};


#endif //MARATONA_SOLUTION_H
