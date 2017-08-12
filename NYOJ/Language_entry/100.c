#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
    int T,t;
    int num;
    int arr[15];

    scanf("%d",&T);
    getchar(  );
    while(T--)
    {
        t = 0;
        memset(arr,0,sizeof(arr));
        scanf("%d",&num);
        while(1)
        {
            arr[t] = num%2;
            num  =num/2;
            t++;
            if(num == 0)
            break;
        }
        for(t = 0;t < 15;t++)
        {
            if(arr[t] == 1)
            num++;
        }
        printf("%d\n",num);
    }

    return 0;
}

/* 本题思路上没有障碍
 *
 * 在实现上,有了些许经验
 *
 * 以后,最好是写while(1)永真循环
 *
 * 可以避免一些不必要的问题
 *
 * 或者循环出来后还要收尾的问题
 *
 * 下面使用与运算的代码很简单
 *
 */



 
#include<stdio.h>
main(){int n,m,s;scanf("%d",&n);while(n--){scanf("%d",&m);s=0;while(m)m&=m-1,s++;printf("%d\n",s);}}        
