/*
 * @filename:    length_of_last_word.cc
 * @author:      Crow
 * @date:        10/13/2018 16:57:08
 * @description:
 */

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream is(s);
        string str;

        while (is >> str) { ; }
        return str.size();
    }
};

int main(void)
{
    Solution temp;
    string s("hello world");

    cout << temp.lengthOfLastWord(s) << endl;
    return 0;
}

// 分析: 使用一般的string处理, 或者耍赖皮, 使用sstream中的isstringstream操作
