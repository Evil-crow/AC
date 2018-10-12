/*
 * @filename:    search_insert_position.cc
 * @author:      Crow
 * @date:        10/12/2018 21:26:55
 * @description:
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {     // 速度已经足够, 4ms
        auto pos(0);

        for (auto i : nums) {
            if (i == target)
                return pos;
            if (i < target)
                pos++;
            if (i > target)
                break;
        }

        return pos;
    }

};

int main(void)
{
    Solution temp;
    vector<int> vec({1, 3, 5, 6});
    auto target(0);

    cout << temp.searchInsert(vec, target) << endl;

    return 0;
}

// 可能会使用的算法: 二分搜索. (未常识, 自认为此解法已经足够简单)
