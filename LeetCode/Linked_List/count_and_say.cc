/*
 * @filename:    count_and_say.cc
 * @author:      Crow
 * @date:        10/13/2018 15:35:42
 * @description:
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        return array[n - 1];
    }
    static int calculate() {
        char num_count('0');
        char num_rec;
        Solution::array[0] += "1";
        for (int i = 1; i < 30; ++i) {
            num_rec = Solution::array[i - 1][0];
            num_count = '0';
            for (auto ch : Solution::array[i - 1]) {
                if (ch == num_rec) {
                    num_count++;
                    continue;
                }
                Solution::array[i] = Solution::array[i] + num_count + num_rec;
                num_count = '1';
                num_rec = ch;
            }
            Solution::array[i] = Solution::array[i] + num_count + num_rec;    // 最后尾部的内容不能忽略
        }
        return 1;
    }
private:
    static string array[30];
};

string Solution::array[30];                                                   // 未使用静态变量时, 64ms -> 4ms
static int ___ = [](){ return Solution::calculate(); }();
int main(void)
{
    Solution temp;
    
    cout << temp.countAndSay(1) << endl;


    return 0;
}

// 分析: 使用迭代求解的, 竟然比我的打表快, 暗自揣测, 应该不是多次取20以上的成员
