/*
 * @filename:    4_replace_blank.cc
 * @author:      Crow
 * @date:        03/12/2019 17:31:17
 * @description:
 *      题目: 请实现一个函数, 把字符串中每个空格替换成"%20".
 *      例如输入"we are happy", 则输出"we%20are%20happy"
 *
 *      主要思想: 从后向前复制, 时间复杂度为O(n), 从前向后复制, 时间复杂度为O(n^2)
 */

#define CATCH_CONFIG_MAIN
#include <iostream>
#include <catch2/catch.hpp>

class Solution {
 public:
  bool ReplaceBlankToCharacter(char *str, int length) {
    if (str == nullptr || length < 0)
      return false;
    
    int origin_len(0), blank_num(0);
    for (int i = 0; str[i] != '\0'; ++i) {
      if (str[i] == ' ')
        blank_num++;
      origin_len++;
    }

    auto new_len(origin_len + 2 * blank_num);
    if (new_len > length)
      return false;

    char *end = str + new_len - 1;
    char *start = str + origin_len - 1;

    while (start != end) {
      if (*start == ' ') {
        start--;
        *end-- = '0';
        *end-- = '2';
        *end-- = '%';
      } else {
        *end = *start;
        end--;
        start--;
      }
    }

    return true;
  }
};

TEST_CASE("Test The Class Solution", "[single-file]") {
  Solution solution;

  SECTION("normally input") {
    char str[30] = "we are happy";
    auto res = solution.ReplaceBlankToCharacter(str, 30);
    REQUIRE(res == true);
    std::cout << str << std::endl;
  }

  SECTION("nullptr") {
    char *str = nullptr;
    auto res = solution.ReplaceBlankToCharacter(str, 0);
    REQUIRE(res == false);
  }

  SECTION("length is not enough") {
    char str[15] = "we are happy";
    auto res = solution.ReplaceBlankToCharacter(str, 15);
    REQUIRE(res == false);
  }
}


// int main(void)
// {
//   char str[30] = "we are happy";
//   Solution solution;
//
//   auto res = solution.ReplaceBlankToCharacter(str, 30);
//   if (res)
//     std::cout << str << std::endl;
// }
