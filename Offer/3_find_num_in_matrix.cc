/*
 * @filename:    find_num_in_matrix.cc
 * @author:      Crow
 * @date:        03/12/2019 16:35:12
 * @description: 
 *    题目: 在一个二维数组中, 每一行都按照从左向右的递增顺序排序
 *    每一列都按照从上到下递增的顺序排序,请完成一个函数, 
 *    输入这样的一个二维数组和一个整数,判断数组中是否含有该整数
 *
 *    备注: 可使用Catch2 测试框架进行测试, 此例中, Bug在Catch2的issue中提出, 尚未解决,
 *          使用传统的main()函数测试, 可获得正确结果
 */

#define CATCH_CONFIG_MAIN
#include <vector>
#include <iostream>
#include <catch2/catch.hpp>

using namespace std;

class Solution {
 public:
  bool FindNumInMatrix(const vector<vector<int>> &vec, int num) {
    auto rows = vec.size();
    auto columns = vec[0].size();

    bool res = false;
    if (!vec.empty() && rows > 0 && columns > 0) {
      auto row(rows - 1);
      auto colum(0);

      while (row > 0 && static_cast<size_t>(colum) < columns) {
        if (vec[row][colum] == num) {
          res = true;
          break;
        } else if (vec[row][colum] > num)
          row--;
        else
          colum++;
      }
    }

    return res;
  }
};

TEST_CASE("Test Class Solution to solve problems", "[single-file]") {
  vector<vector<int>> vec;
  Solution solution;

  SECTION("正常测试") {
    vec = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 15, 16}
    };

    REQUIRE(solution.FindNumInMatrix(vec, 7) == true);
    REQUIRE(solution.FindNumInMatrix(vec, 100) == false);
  }

  SECTION("空向量测试") {
    vec = {};

    REQUIRE(solution.FindNumInMatrix(vec, 7) == false);
  }
}

// int main(void)
// {
//   Solution solution;
//   vector<vector<int>> vec{
//     {1, 2, 3, 4},
//     {5, 6, 7, 8},
//     {9, 10, 11, 12},
//     {13, 14, 15, 16},
//   };
//   cout << solution.FindNumInMatrix(vec, 7) << endl;
//
//   vec = {};
//   cout << solution.FindNumInMatrix(vec, 7) << endl;
// }
