/*
 * @filename:    roman_to_integer.cc
 * @author:      Crow
 * @date:        10/09/2018 22:43:34
 * @description:
 */

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        char ch = s[0];
        
        for (auto &i : s) {
            switch (i) {
                case 'I': res += 1; break;
                case 'V': res += (ch == 'I') ? 3 : 5; break;
                case 'X': res += (ch == 'I') ? 8 : 10; break;
                case 'L': res += (ch == 'X') ? 30 : 50; break;
                case 'C': res += (ch == 'X') ? 80 : 100; break;
                case 'D': res += (ch == 'C') ? 300 : 500; break;
                case 'M': res += (ch == 'C') ? 800 : 1000; break;
            }
            ch = i;
        }
        
        return res;
    }
};

int main(void)
{
    Solution temp;

    cout << temp.romanToInt("XIV") << endl;
    return 0;
}

/*
 * 解题思路: 就是进行字符串的处理行为
 *
 * 其中注意处理, 前缀做减法的情况即可, 
 *
 * 其他的解法, 也都是在处理手段上, 略有异同
 *
 */
