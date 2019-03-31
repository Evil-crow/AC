/*
 * @filename:    12_1_to_n.cc
 * @author:      Crow
 * @date:        03/31/2019 21:11:21
 * @description:
 *      问题描述: 需要注意的是大数问题
 *                int, long都是会溢出的
 *      思路描述: 1. 特殊化字符串, 并且提供加法操作
 *                2. 使用递归完成全排列
 *                提供特殊的PrintNum(), 取消前导0
 */
#include <iostream>

// 打印函数, 跳过前导0, 输出符合阅读习惯的内容
void PrintNum(char *str) {
  for (int i = 0; str[i] != '\0'; ++i) {
    if (str[i] == '0')
      continue;
    printf("%s\n", str);
  }
}

// 进行递归打印, 直到将所有pos上填满之后, 才能输出, 即index == length - 1
void PrintNumRecursive(char *str, int length, int index) {
  if (index == length - 1) {
    PrintNum(str);
    return ;
  }

  for (int i = 0; i < 10; ++i) {
    str[index + 1] = i + '0';
    PrintNumRecursive(str, length, index + 1);
  }
}

void PrintOneToN(int n) {
  if (n <= 0)
    return ;

  char *str = new char[n + 1];
  str[n] = '\0';                                 // C-Style, 结尾为终止字符'\0'

  for (int i = 0; i < 10; ++i) {
    str[0] = i + '0';
    PrintNumRecursive(str, n, 0);                // 初始index == 0
  }

  delete[] str;                                  // 避免内存泄漏
}

int main(void) {
  PrintOneToN(2);
  PrintOneToN(1);
}
