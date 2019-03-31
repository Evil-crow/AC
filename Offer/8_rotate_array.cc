/*
 * @filename:    8_rotate_array.cc
 * @author:      Crow
 * @date:        03/31/2019 17:44:23
 * @description: 旋转数组的整体思路采用二分查找进行求解
 *              遇到有重复数字, 进行遍历求解即可
 */

#include <iostream>
#include <vector>

int SearchInOrder(const std::vector<int> &vec, int i, int j) {
  auto temp = vec[i];
  for (int t = i + 1; t <= j; ++t) {
    if (temp > vec[t])
      temp = vec[t];
  }

  return temp;
}

int MinInRotateArray(const std::vector<int> &vec) {
  int begin = 0;
  int end = vec.size() - 1;

  while (begin <= end) {                         // 循环条件
    if (end - begin == 1)                        // 结果一定在vec[right]中
      return vec[end];

    auto mid = (begin + end) / 2;
    if (vec[begin] == vec[end] &&                // 无法判断时, 采用序列遍历查找
        vec[begin] == vec[mid] &&
        vec[mid] == vec[end])
      return SearchInOrder(vec, begin, end);

    if (vec[mid] > vec[begin])                   // 结果在右侧
      begin = mid;
    if (vec[mid] < vec[end])                     // 结果在左侧
      end = mid;
  }
}

int main(void) {
  std::vector<int> vec{3, 4, 5, 0, 1, 2};
  std::vector<int> vec1{1, 0, 1, 1, 1, 1};
  std::vector<int> vec2{1, 1, 1, 1, 0, 1};
  auto res = MinInRotateArray(vec1);

  std::cout << res << std::endl;
}
