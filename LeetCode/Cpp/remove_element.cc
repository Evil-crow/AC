/*
 * @filename:    remove_element.cc
 * @author:      Crow
 * @date:        10/11/2018 17:02:26
 * @description:
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(), nums.end());
        auto nums_begin = find(nums.begin(), nums.end(), val);
        auto nums_end = find_if(nums_begin, nums.end(),[val](int n){ return n != val; });
        nums.erase(nums_begin, nums_end);

        return nums.size();
    }
};

// int remove_element(vector<int> &nums, int val);

int main(void)
{
    Solution temp;

    vector<int> vec({0, 1, 2, 2, 3, 0, 4, 2});
    cout << temp.removeElement(vec, 2) << endl;
    for (auto i : vec)
        cout << i << " ";
    cout << endl;

    return 0;
}

/*
 * 其他思路: 类似于之前一道删除重复元素的题目,
 * 不过,想用用泛型算法解题, 效率上, 起码oj上还不是很明显,差不多
 * 仍然是, 取消stdio同步的机灵鬼在前面
 */

// int remove_element(vector<int> &nums, int val)
// {
//     auto pos(0);
//
//     for (auto i : nums) {
//         if (i != val)
//             nums[pos++] = i;
//     }
//
//     return pos;
// }

