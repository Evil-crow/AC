/*
 * @filename:    merge_sort.cc
 * @author:      Crow
 * @date:        03/30/2019 16:17:44
 * @description: 
 *          归并排序  --采用分治的思想, 对数组进行拆分, 分到不可再分的程度
 *          之后开始进行归并操作, 最后完成数组的合并
 *          主要是可以支持外排序
 *          平均/最差时间复杂度均是O(NlogN), 是稳定排序
 *
 *          优化措施:
 *          1. 可以使用同一个临时数组, 避免多次new, delete
 *          2. 递归到足够小的规模时, 可以使用插入排序来提高效率
 */

#include <iostream>
#include <vector>

template <typename T>
void Merge(std::vector<T> &vec, int L, int M, int R) {
  // std::vector<T> vecA_(M - L);
  // std::vector<T> vecB_(R - M + 1);                   // 我们使用std::vector::emplace_back, 所以无需进行X大小的初始化构造
  std::vector<int> vecA_, vecB_;

  for (int i = L; i < M; ++i)
    vecA_.emplace_back(vec[i]);
  for (int i = M; i <= R; ++i)
    vecB_.emplace_back(vec[i]);

  // 此处的循环次数是{min(A.size(), B.size()), A.size() - 1 + B.size() - 1},
  // 所以严格使用 while (indexA_ < vecA_.size() && indexB_ < vecB_.size()) 作为判断条件
  // 不能简单使用最小值进行倒计时, 判断循环次数.
  
  size_t indexA_(0), indexB_(0), indexVec(L);
  while (indexA_ < vecA_.size() && indexB_ < vecB_.size()) {
    if (vecA_[indexA_] < vecB_[indexB_])
      vec[indexVec++] = vecA_[indexA_++];
    else
      vec[indexVec++] = vecB_[indexB_++];
  }
  if (indexA_ < vecA_.size())
    for (; indexA_ < vecA_.size(); indexA_++)
      vec[indexVec++] = vecA_[indexA_];
  if (indexB_ < vecB_.size())
    for (; indexB_ < vecB_.size(); indexB_++)
      vec[indexVec++] = vecB_[indexB_];

}

template <typename T>
void MergeSort(std::vector<T> &vec, int L, int R) {
  if (L == R || L > R)
    return ;

  auto M = (L + R) / 2;
  MergeSort(vec, L, M);                       // 使用(L, M),(M + 1, R), 并非(L, M+1),(M, R), 考虑了M为0的情况
  MergeSort(vec, M + 1, R);
  Merge(vec, L, M + 1, R);
}

int main(void)
{
  std::vector<int> vec{1, 4, 5, 2, 3};
  MergeSort(vec, 0, vec.size() - 1);
}
