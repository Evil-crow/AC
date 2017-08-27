#include<stdio.h>
#include<string.h>
int main(void)
{
    long ni;                                       //录入需要进行进制转换的数
    int _result[1000];                             //存取二进制结果的数组
    int t,m;
   
    while(scanf("%ld",&ni) != EOF)
    {
        printf("ni:%ld\n",ni);
        memset(_result,0,1000);
        t = 0;
        if(ni == 0)
        {
            printf("0\n");
            continue;
        }
        while(ni != 0)
        {
            _result[t++] = ni%2;
            ni = ni/2;
        }
        m = t;
        for(t = m;t != 0;t--)
            printf("%d",_result[t]);
        printf("\n");
        for(t = m;t != 0;t--)
            if(_result[t] == 1)
            break;
        for(t += 1;t != 0;t--)
            printf("%d",_result[t]);
        printf("\n");
    }

    return 0;
}
