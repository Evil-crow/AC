/*
 * @filename:    14_even_odd.cc
 * @author:      Crow
 * @date:        03/31/2019 22:02:42
 * @description:
 *          问题描述: 将数组中奇数放在前半部分, 偶数放在后半部分
 *          解法: 首尾指针, 遇到符合条件时, 进行std::swap即可
 *          扩展性: 提供std::function<T> cmp进行区分.
 *                  可使用函数指针, 函数子(Functor), std::bind, 或者lambda expr皆可
 */

#include <iostream>
#include <vector>
#include <functional>

void Recoder(std::vector<int> &vec, std::function<bool (int)> cmp) {
  int indexA_ = 0;
  int indexB_ = vec.size() - 1;

  while (indexA_ < indexB_) {
    while (indexA_ < indexB_ && cmp(vec[indexA_]))         // 一定要有indexA_ < indexB_
      indexA_++;
    while (indexA_ < indexB_ && !cmp(vec[indexB_]))        // 一定要有indexA_ < indexB_
      indexB_--;

    std::swap(vec[indexA_], vec[indexB_]);
  }
}

int main(void) {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Recoder(vec, [](int i){ return i % 2 != 0; });           // 此处使用lambda expr, 使用functor也是完全可以的

  for (const auto &var : vec)
    std::cout << var << " ";
  std::cout << std::endl;
}
