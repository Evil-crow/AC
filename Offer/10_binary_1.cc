/*
 * @filename:    10_binary_1.cc
 * @author:      Crow
 * @date:        03/31/201-9 1-9:27:05
 * @description:
 *            求二进制中有多少个1
 *            思路:
 *              1. 右移, 与1与运算, 计数  (负数会无限循环, 可考虑>>>)
 *              2. 修改1, 每次左移flags, 转换思路即可
 *              3. n = (n - 1) & n;
 *            
 *            类似题目:
 *              1. 判断是否为2的整数幂, (2的整数幂中, 只有一个1)
 *              2. 判断m, n修改几位才能相等. 首先异或, 计算多少个1, 即要修改多少位
 */

#include <iostream>

int judge_right(int num) {
  int count = 0;
  while (num) {
    if (num & 1)
      count++;
    num  = num >> 1;
  }
  return count;
}

int judge_left(int num) {
  int count = 0;
  int flags = 1;

  while (flags) {
    if (num & flags)
      count++;
    flags <<= 1;
  }

  return count;
}

int judge(int num) {
  int count = 0;

  while (num) {
    count++;
    num &= (num - 1);
  }
  return count;
}

int main(void) {
  std::cout << judge_right(-9) << std::endl;
  std::cout << judge_left(-9) << std::endl;
  std::cout << judge(-9) << std::endl;
}
