/*
 * @filename:    valid_parentheses.cc
 * @author:      Crow
 * @date:        10/10/2018 20:54:36
 * @description:
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> vec;

        for (auto &i : s) {
            if (i == '{' || i == '[' || i == '(')
                vec.emplace_back(i);
            if (i == '}') {
                if (vec.empty()) return false;          // 当判断右括号时, 注意: vec中为空直接false, 否则vec.back() -> Core Dump !!!
                if (vec.back() != '{')
                    return false;
                vec.pop_back();
            }
            if (i == ']') {
                if (vec.empty()) return false;
                if (vec.back() != '[')
                    return false;
                vec.pop_back();
            }
            if (i == ')') {
                if (vec.empty()) return false;
                if (vec.back() != '(')
                    return false;
                vec.pop_back();
            }
        }

        if (vec.empty())                          // 即使字符串parser完毕, 也要判断是否为空, 如果有残余, 仍然是false
            return true;
        return false;
    }
};

int main(void)
{
    Solution temp;

    string question("]");
    cout << temp.isValid(question) << endl;

    return 0;
}


/*
 * 总体思路仍然是使用stack来进行匹配操作
 * 逐个字符判断即可,
 * 不过其中: 可以使用std::map使得算法更高效 ? (活用STL), 
 * 至于是否高效于底层操作, 持保留态度
 * 简单题目, 没有多余讨论意义
 */
