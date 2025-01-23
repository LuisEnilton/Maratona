cmake_minimum_required(VERSION 3.25)
project(Maratona)

set(CMAKE_CXX_STANDARD 14)

include_directories(LeetCode)
include_directories("LeetCode/1047. Remove All Adjacent Duplicates In String")
include_directories("LeetCode/11. Container With Most Water")
include_directories("LeetCode/118 - Pascal's Triangle")
include_directories("LeetCode/119 - Pascal's Triangle II")
include_directories("LeetCode/14. Longest Common Prefix")
include_directories("LeetCode/155. Min Stack")
include_directories("LeetCode/198 - HouseRobber")
include_directories("LeetCode/2. Add Two Numbers")
include_directories("LeetCode/213 - House Robber II")
include_directories("LeetCode/221 - Maximal Square")
include_directories("LeetCode/3- Substring Without Repeating Characters")
include_directories("LeetCode/300 - Longest Increasing Subsequence")
include_directories("LeetCode/33. Search in Rotated Sorted Array")
include_directories("LeetCode/336 - Palindrome Pairs")
include_directories("LeetCode/35 - Search Insert Position")
include_directories("LeetCode/409 - Longest Palindrome")
include_directories("LeetCode/455 - Assign Cookies")
include_directories("LeetCode/486 - Predict the Winner")
include_directories("LeetCode/5-Longest Palindromic Substring")
include_directories("LeetCode/561 - Array Partition")
include_directories("LeetCode/62. Unique Paths")
include_directories("LeetCode/63. Unique Paths II")
include_directories("LeetCode/64 - Minimum Path Sum")
include_directories("LeetCode/69 - Sqrt(x)")
include_directories("LeetCode/7. Reverse Integer")
include_directories("LeetCode/70 - Climbing Stairs")
include_directories("LeetCode/74-Search a 2D Matrix")
include_directories("LeetCode/740-Delete and Earn")
include_directories("LeetCode/746 - Min Cost Climbing Stairs")
include_directories("LeetCode/796 - Rotate String")
include_directories("LeetCode/852-Peak Index in a Mountain Array")
include_directories("LeetCode/9. Palindrome Number")
include_directories("LeetCode/931. Minimum Falling Path Sum")
add_executable(new_targetj a.cpp)
add_executable(new_target1 "Codeforces/4C - Registration system/solution.cpp")

add_executable(a Codeforces/Div4-971/g.cpp
        "Summer/Dia 2/f.cpp"
        "Summer/Dia 2/g.cpp"
        "Summer/Dia 2/h.cpp"
        Summer/Dia1/j.cpp
        Summer/Dia1/c.cpp
        Summer/Dia1/d.cpp
        "Summer/Dia 3/l.cpp"
        "Summer/Dia 3/ES/secret.cpp"
        Biblioteca/DS/DisjointSparseTable.cpp)
add_executable(b "CSES/Sorting and Searching/NestedRangesCount.cpp"
        "CSES/Sorting and Searching/SlidingWindowMedian.cpp")
