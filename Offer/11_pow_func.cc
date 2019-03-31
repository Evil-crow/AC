/*
 * @filename:    11_pow_func.cc
 * @author:      Crow
 * @date:        03/31/2019 20:37:27
 * @description: 
 *      问题描述: 实现整数的 pow(),不考虑大数问题
 *      思路: 注意边界值以及错误值的考虑
 *           例如负指数 和 0底数
 *           协商0指数的结果
 */

#include <iostream>

double pow_impl(double base, long index) {
  double result = 1.0;
  while (index) {
    result *= base;
    index--;
  }
  return result;
}

double pow_(double num, long index) {
  if (index < 0 && std::abs(num - 0) < 0.0000001)
    throw std::runtime_error(" / 0");
  
  auto abs_index = index;
  if (index < 0)
    abs_index = 0 - index;
  
  auto result = pow_impl(num, abs_index);
  if (index < 0)
    result = 1.0 / result;
  
  return result;
}

int main(void) {
  std::cout << pow_(2.0, 2) << std::endl;
  std::cout << pow_(-2.0, -2) << std::endl;
  std::cout << pow_(0, -2.0) << std::endl;
}
