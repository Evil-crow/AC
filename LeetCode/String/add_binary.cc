/*
 * @filename:    add_binary.cc
 * @author:      Crow
 * @date:        10/14/2018 15:50:06
 * @description:
 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        return dec_to_bin(bin_to_dec(a) + bin_to_dec(b)); 
    }

private:
    long long bin_to_dec(string num) {
        long long res(0), power(0);
        for (auto iter = num.rbegin(); iter != num.rend(); ++iter)
            res += (*iter - '0') * pow(2, power++);
        return res;
    }

    string dec_to_bin(long long num) {
        if (num == 0)
            return string("0");
        string res;

        while (num) {
            res += (num % 2) + '0';
            num /= 2;
        }

        return string(res.crbegin(), res.crend());
    }
};

int main(void)
{
    Solution temp;
   
    cout << temp.addBinary("0", "1011");
    
    return 0;
}
