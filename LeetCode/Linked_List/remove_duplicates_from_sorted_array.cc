/*
 * @filename:    remove_duplicates_from_sorted_array.cc
 * @author:      Crow
 * @date:        10/11/2018 11:15:17
 * @description: 此实现, 基于STL, 但是效率并没有多高. 后面提出高效的答案
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        auto record(nums[0]);
        for (auto iter = nums.begin() + 1; iter != nums.end(); ++iter) {
            if (*iter == record) {
                nums.erase(iter);               // 会导致迭代器移动到下一个位置
                iter--;                         // 自减回到正常位置
                continue;
            }
            record = *iter;                     // 更改记录
        }

        return nums.size();
    }
};

int remove_duplicates(vector<int> &nums);

int main(void)
{
    Solution temp;

    vector<int> vec({0, 0, 1, 1, 1, 2, 2, 3, 3, 4});
    cout << temp.removeDuplicates(vec) << endl;

    for (auto i : vec)
        cout << i << " ";
    cout << endl;

    return 0;
}

/*
 * 关于此题: 可以使用简单地思想, 因为是有序数组
 * 可以设置两个标兵, 一个i正常遍历, 一个j是在改变后移动的
 * j 当且仅当 nums[i] != nums[j] 时, => nums[++j] = nums[i];
 * 最后, 整个数组, 从 0->j下标处为去重内容
 * 不需要真正的去重, 因为外面的验证时根据len来判断的
 * 核心代码:
 */

// int remove_duplicates(vector<int> &nums)
// {
//     if (nums.empty())
//         return 0;
//
//     auto pos(0);
//     for (size_t i = 1; i < nums.size(); ++i) {
//         if (nums[pos] != nums[i])
//             nums[++pos] = nums[i];
//     }
//
//     return pos + 1;
// }
