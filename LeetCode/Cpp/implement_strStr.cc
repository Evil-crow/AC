/*
 * @filename:    implement_strStr.cc
 * @author:      Crow
 * @date:        10/12/2018 20:38:19
 * @description:
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {                // 本来以为这个效率低, 64ms
        auto pos(-1);
        auto begin = haystack.cbegin();
        auto end = haystack.cend();
        auto size = needle.size();

        if (needle.empty())
            return 0;
        
        for (auto iter = begin; iter != end; ++iter) {
            if (*iter == needle[0]) {
                pos = iter - begin;
                string temp(iter, iter + size);
                if (temp == needle)
                    return pos;
            }
        }
    
        return -1;
    }

    int _strStr(string haystack, string needle) {               // 完了, 这个效率更低, 644ms
        auto pos(-1);
        auto haystack_size(haystack.size());
        auto flag(true);

        if (needle.empty())
            return 0;
        for (size_t i = 0; i < haystack_size; ++i) {
            if (haystack[i] == needle[0]) {
                pos = i;
                int j = 0;
                auto len = needle.size();
                while (len--) {
                    flag = true;
                    if (haystack[i + j] != needle[j]) {
                        flag = false;
                        break;
                    }
                    j++;
                }
                if (flag)
                    return pos;
            }
        }

        return -1;
    }
};

int main(void)
{
    Solution temp;
    string haystack("mississippi");
    string needle("issip");

    cout << temp._strStr(haystack, needle) << endl;
    return 0;
}

/*
 * 思路: 女乃女乃的, 每次我都是低效算法...
 *
 * 思路两种呗:
 * 1. 基于字符串的比较做法, 使用标兵记录的方法
 * 2. 使用容器的迭代, 构造比较, 不过这种好像往往都是低效的做法, 因为成本太大
 * 3. KMP
 */
