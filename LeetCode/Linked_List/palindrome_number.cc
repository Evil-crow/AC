/*
 * @filename:    palindrome_number.cc
 * @author:      Crow
 * @date:        10/09/2018 22:36:56
 * @description:
 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        auto str = std::to_string(x);
        std::string rstr(str.crbegin(), str.crend());

        return (str == rstr);
    }
};

int main(void)
{
    Solution temp;
    int x = 345543;

    cout << temp.isPalindrome(x) << endl;

    return 0;
}

/* 
 * 解题思路: 使用反向迭代器进行构造, 直接完成比较即可
 *
 * 缺点: 有的时候, 首尾直接判断比较即可, 构造反而造成一定的效率低下
 *
 * 提升: 可以使用字符串分割处理, 首尾双向开始比较即可,
 * 另类, 使用std::accumulate进行首尾相加, 比较结果也行
 */
