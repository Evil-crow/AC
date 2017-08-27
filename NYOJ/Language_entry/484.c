#include<stdio.h>
#include<string.h>
int main(void)
{
    char str[8];
    int i;
    int t = 1;
    char clock[12][8] = {
        {"I"},
        {"II"},
        {"III"},
        {"IV"},
        {"V"},
        {"VI"},
        {"VII"},
        {"VIII"},
        {"IX"},
        {"X"},
        {"XI"},
        {"XII"}
    };
    int _clock[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    while(scanf("%s",str) != EOF)
    {
        for(i = 0;i < 12;i++)
        {
            if(strcmp(str,clock[i]) == 0)
            {
                printf("Case %d: %d\n",t,_clock[i]);
                t++;
                continue;
            }
        } 
    }

    return 0;
}


/* 此题解法还是粗暴的直接上数组,挺方便的,用时间效率换性能
 *
 * 中间出问题在于,连续用scanf,使得有时录入数据无效,需要录入2两次出错
 *
 * So,去掉一个scanf即可
 *
 * 下面是标准的C++解法,使用map,真TM的方便
 *
 */
 
#include<map>
#include<iostream>
#include<string>
using namespace std;
map<string,int>m;
int main()
{
	m["I"]=1;
	m["II"]=2;
	m["III"]=3;
	m["IV"]=4;
	m["V"]=5;
	m["VI"]=6;
	m["VII"]=7;
	m["VIII"]=8;
	m["IX"]=9;
	m["X"]=10;
	m["XI"]=11;
	m["XII"]=12;
	string s;
	int c=0;
	while(cin>>s)
		cout<<"Case "<<++c<<": "<<m[s]<<endl;
	return 0;
}        
