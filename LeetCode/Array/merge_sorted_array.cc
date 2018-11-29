/*
 * @filename:    merge_sorted_array.cc
 * @author:      Crow
 * @date:        10/15/2018 20:52:46
 * @description:
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto i(0);
        for (auto iter = nums1.begin() + m; iter != nums1.begin() + m + n; ++iter) {
            *iter = nums2[i++];
        }
        std::sort(nums1.begin(), nums1.end());
    }

    // 下面这个形式的循环, 更容易理解. 以nums2的元素插入为准
    void _merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto iter(nums1.begin() + m);
        for (int i = 0; i < n; ++i) {
            *iter++ = nums2[i];
        }
        std::sort(nums1.begin(), nums1.end());
    }
};

int main(void)
{
    Solution temp;
    vector<int> num1({1, 2, 3, 0, 0, 0});
    vector<int> num2({4, 5, 6});

    temp.merge(num1, 3, num2, 3);

    for (auto i : num1) 
        cout << i << " ";
    cout << endl;
    return 0;
}
