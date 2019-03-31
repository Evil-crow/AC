/*
 * @filename:    insert_sort.cc
 * @author:      Crow
 * @date:        03/30/2019 22:01:21
 * @description:
 *             插入排序: 将当前位置的元素插入已经排序的序列之中.
 *             平均时间复杂度O(N^2), 最坏也是, 是稳定排序
 */

#include <iostream>
#include <vector>

void InsertSort(std::vector<int> &vec) {
  for (size_t i = 1; i < vec.size(); ++i) {      // 控制排序趟数
    auto temp = vec[i];

    int j = i - 1;                               // 已经排序序列的末位
    for (; j >= 0; --j) {                        // 从当前index处向前倒序
      if (vec[j] > temp)                         
        vec[j + 1] = vec[j];                     // 从前向后覆盖
      else
        break;
    }
    vec[j + 1] = temp;                           // 找到合适的位置
  }
}

int main(void) {
  std::vector<int> vec{1, 2, 6, 4, 7, 8};
  InsertSort(vec);
  for (const auto &var : vec)
    std::cout << var << std::endl;
}
