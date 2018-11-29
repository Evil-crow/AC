/*
 * @filename:    longest_common_prefix.cc
 * @author:      Crow
 * @date:        10/09/2018 22:04:18
 * @description:
 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return string();
        string res(strs[0]);
        for (size_t i = 0; i < strs.size(); ++i) {
           res =  getString(res, strs[i]);
           if (res == "")
               return res;
        }
        return res;
    }
private:
    string getString(string &lhs, string &rhs) {
        string res("");
        auto size = (lhs.size() > rhs.size()) ? rhs.size() : lhs.size();
        
        for (size_t i = 0; i < size; ++i) {
            if (lhs[i] != rhs[i])
                break;
            res += lhs[i];
        }
        return res;
    }
};

int main(void)
{
    Solution temp;

    vector<string> vec;
    cout << temp.longestCommonPrefix(vec) << endl;

    return 0;
}

/* 
 * 解法: 后面确实提到了好几种其他的思路
 * , 基本上是搜索策略的不同, 有时间得琢磨一下, 英语水平有限
 */
