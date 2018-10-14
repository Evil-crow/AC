/*
 * @filename:    plus_one.cc
 * @author:      Crow
 * @date:        10/14/2018 14:55:31
 * @description:
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {                  // 0ms 或者,4ms 时间不稳定
        auto iter = digits.rbegin();
        auto iter_end = digits.rend();
        for (; iter != iter_end; ++iter) {
            if (*iter != 9) {
                *iter = (*iter + 1) % 10;
                break;                                          // 无进位, 直接跳出loop
            } else
                *iter = (*iter + 1) % 10;

            // 测试: 会有[9], 此类样例, 所以不能略去此部分
            if (iter == iter_end - 1 && *iter == 0) {           // 处理位数超限: 重新构造 (臆测这也是返回值的原因)
                vector<int> vec({1});
                for (const auto &i : digits)
                    vec.emplace_back(i);
                return vec;
            }
        }

        return digits;
    }
};

int main(void)
{
    Solution temp;
    vector<int> vec({9, 9});

    auto x = temp.plusOne(vec);

    for (auto i : x)
        cout << i << ", ";
    cout << endl;

    return 0;
}
