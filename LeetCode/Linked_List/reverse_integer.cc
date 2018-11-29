/*
 * @filename:    reverse_integer.cc
 * @author:      Crow
 * @date:        10/08/2018 17:11:34
 * @description:
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool flag = false;
        if (x < 0) {
            flag = true;
            x = 0 - x;
        }

        auto str = std::to_string(x);
        auto pos = str.find_last_not_of('0') + 1;

        str = str.substr(0, pos);
        std::string nstr(str.crbegin(), str.crend());    // get the sub string
        auto res = std::strtoll(nstr.c_str(), NULL, 10);

        // long a = pow(2, 31) - 1;
        // if (res > a || res < (-a - 1))
        //     return 0;
        if (res > INT_MAX || res < INT_MIN)
            return 0;
        if (flag)
            return -res;
        return res;
    }
};

/*
 * int main(void)
 * {
 *   Solution temp;
 *
 *   cout << temp.reverse(1999999999) << endl;
 *
 *   return 0;
 * }
 */

/*
 * 标程解法:
 * 使用pop/push的做法. (PS: 想起当年Root学长在我二面时问到的问题,)
 * 其中可取之处: INT_MAX, 以及
 * auto i = x % 10;
 * x /= 10;
 *
 * res += i * 10;
 * return res;
 */
