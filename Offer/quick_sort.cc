/*
 * @filename:    8_quick_sort.cc
 * @author:      Crow
 * @date:        03/30/2019 11:31:35
 * @description: 
 *         快速排序是一种基于分治思想的算法, 使用递归对子序列进行求解
 *         下面介绍三种:
 *         1. 基本的快速排序, 基于CLRS
 *         2. 三层分治, 对于有重复元素出现的子序列, 不将其投入到递归中处理
 *         3. 使用HashFunc等进行随机基准数的选取
 *         快速排平均的时间复杂度为O(NlogN), 最坏情况为O(N^2)
 *
 *         优化措施:
 *         1. 随机选择pivot
 *         2. 重复元素多时, 可考虑三路快排
 */

#include <iostream>
#include <vector>

// 1. 基本快速排序 => 基于CLRS的尾节点分界
template <typename T>
int Partition(std::vector<T> &vec, int low, int high) {
  auto pivot = vec[high];                                   // 同CLRS, 以为尾巴节点
  auto k = low;

  for (int i = low; i < high; ++i)                          // 核心思想: 大的continue, 小的进行替换
    if (vec[i] < pivot)
      std::swap(vec[i], vec[k++]);
  std::swap(vec[k], vec[high]);                             // 最后将基准值交换至合适的位置

  return k;
}

template <typename T>
void QuickSort(std::vector<T> &vec, int low, int high) {
  if (low < high ) {                                        // 子序列仍然待排序
    auto pivot = Partition(vec, low, high);                 // 获取到pivot的分界点
    QuickSort(vec, low, pivot - 1);                         // 对左序列排序
    QuickSort(vec, pivot + 1, high);                        // 对右序列排序
  }
}


// 2. 处理存在大量相同元素的情况, 节点区分相同序列的左右界
template <typename T>
std::pair<int, int> Partition(std::vector<T> &vec, int low, int high) {
  auto pivot = vec[high];
  auto temp_l(low), temp_h(high);

  for (int i = low; i < high; ++i) {                                // int i = low, 并非是0, 切记!
    if (vec[i] < pivot)
      std::swap(vec[i], vec[temp_l++]);                             // 小的往前移
    else if (vec[i] == pivot)
      std::swap(vec[i], vec[temp_h--]);                             // 相等的往后放
    else
      continue;                                                     // 大的不做处理
  }

  auto seq = std::min(temp_h - temp_l, high - temp_h + 1);          // 选取左右区间间隔与重复元素数目中的较小值
  for (int i = 0; i < seq; ++i)
    std::swap(vec[temp_l + i], vec[high - i]);                      // 将vec后部的重复元素进行搬移

  return {temp_l, high - temp_h + temp_l};                          // 元素搬移之后, temp_h位置并未发生改变, 我们需要计算比pivot大的值, 从而推算右界点
}

template <typename T>
void QuickSort_II(std::vector<T> &vec, int low, int high) {
  if (low < high) {
    auto pivot = Partition(vec, low, high);
    QuickSort(vec, low, pivot.first - 1);
    QuickSort(vec, pivot.second + 1, high);
  }
}


// 3. 随机选取pivot
// 此种形式的区别主要是在pivot的选取上, 
// 常用hash或者RandomAccess进行选取即可
// 此处不再举例

int main(void)
{
  std::vector<int> vec{3, 4, 5, 6, 1, 1, 2, 1, 1, 10};

  QuickSort(vec, 0, vec.size() - 1);
  QuickSort_II(vec, 0, vec.size() - 1);

  for (const auto &var : vec)
    std::cout << var << std::endl;
}
