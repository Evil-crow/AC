/*
 * @filename:    climb_stairs.cc
 * @author:      Crow
 * @date:        10/14/2018 16:30:15
 * @description:
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {                   // 取值
        return Solution::array[n - 1];
    }

    static int calculate() {                   // 打表 f(n) = f(n - 1) + f(n - 2), f(0) = 1, f(1) = 2...
        Solution::array[0] = 1;
        Solution::array[1] = 2;
        for (int i = 2; i < 1000; ++i)
            Solution::array[i] = Solution::array[i - 1] + Solution::array[i - 2];
        return 1;
    }

private:
    static long array[1000];
};

long Solution::array[1000];
int ___ = [](){ return Solution::calculate(); }();
