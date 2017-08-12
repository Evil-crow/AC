#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
    char str[15];
    char temp[4];
    char p;
    int a,b,c,result,length;
    int flag;
    int sum = 0;

    while(scanf("%s",str) != EOF)
    {
        int i,j,x,t;
        flag = 0;
        length = strlen(str);
        for(x = 0;x < length;x++)
        {
            if(str[x] == '+' || str[x] == '-')
            i = x;
            if(str[x] == '=')
            j = x;
        }
        for(x = 0;x < i;x++)
            temp[x] = str[x];
        temp[x] = '\0';
        a = atoi(temp);
        for(x = i+1,t = 0;x < j;x++)
            temp[t++] = str[x];
        temp[t] = '\0';
        b = atoi(temp);
        for(x = j+1,t = 0;x < length;x++)
            temp[t++] = str[x];
        temp[t] = '\0';
        if(strcmp(temp,"?") == 0)
        {
            flag = 1;
        }
        else
        c = atoi(temp);
        if(str[i] == '-')
        result = a-b;
        else
        result = a+b;
        if(flag == 1)
        continue;
        if(result == c)
        sum++;
        else
        continue;
    }
    printf("%d",sum);

    return 0;
}

/* 此题的重点在于对字符串的解析
 *
 * 一开始我也是一个一个去搞
 *
 * 后来发现,其实不对,那样很难处理
 *
 * 因为每一行不长
 *
 * 所以,事实上,遍历一遍,记录三个符号位的位置
 *
 * 之后分段解析,使用atoi进行字符串的转换
 *
 * 最后进行运算处理,并统计结果即可
 *
 */
