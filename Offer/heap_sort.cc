/*
 * @filename:    heap_sort.cc
 * @author:      Crow
 * @date:        03/30/2019 20:24:46
 * @description:
 *            堆排序是选择排序的一种.
 *            平均, 最差时间复杂度都是O(NlogN)
 *            是不稳定排序.
 */

#include <iostream>
#include <vector>

// 建堆具体实现函数, 递归进行处理, 如果不满足max-heap则会进行下滤
void MakeHeapIfNeeded(std::vector<int> &vec, int current, int size) {
  if (current <= size) {
    auto left(2 * current + 1), right(2 * current + 2), max(current);
    
    if (left <= size)
      if (vec[left] > vec[max])
        max = left;

    if (right <= size)
      if (vec[right] > vec[max])
        max = right;

    if (max != current) {
      std::swap(vec[current], vec[max]);
      MakeHeapIfNeeded(vec, max, size);
    }
  }
}

// 建堆函数
void MakeHeap(std::vector<int> &vec, int size) {
  for (int i = size; i >= 0; --i)
    MakeHeapIfNeeded(vec, i, size);
}

// 堆排接口
void HeapSort(std::vector<int> &vec) {
  MakeHeap(vec, static_cast<int>(vec.size() - 1));           // 初始序列是不满足max-heap的, 首先建堆一次
  
  for (int i = 0; i < static_cast<int>(vec.size()); ++i) {
    MakeHeap(vec, static_cast<int>(vec.size()) - i - 1);     // 建堆
    std::swap(vec[0], vec[vec.size() - i - 1]);              // 首元素移至反向适宜位置
  }
}

int main(void) {
  std::vector<int> vec{1, 4, 6, 2, 3, 4};
  HeapSort(vec);

  for (const auto &var : vec)
    std::cout << var << std::endl;
}
