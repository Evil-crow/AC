/*
 * @filename:    9_fibonacci.cc
 * @author:      Crow
 * @date:        03/31/2019 17:59:26
 * @description:
 *             递归, 循环, 打表 => 减少重复运算
 *             思路: 从f(n)出发, 转换为子问题的求解
 *             同类型还有: 青蛙跳台阶, 放瓷砖, 都是同类型的题目
 *                        递归即可以用来求解此类, 可拆分为子问题的情况
 */

#include <iostream>

long fibonacci_recursion(long i) {
  if (i == 1)
    return 1;
  if (i == 2)
    return 1;
  return fibonacci_recursion(i - 1) + fibonacci_recursion(i - 2);
}

long fibonacci_loop(long i) {
  long a = 1;
  long b = 1;
  long res;

  for (int t = 3; t <= i; ++t) {
    res = a + b;
    a = b;
    b = res;
  }

  if (i < 3)
    return a;
  return res;
}

int main(void) {
  std::cout << fibonacci_recursion(5) << std::endl;
  std::cout << fibonacci_loop(5) << std::endl;
}
