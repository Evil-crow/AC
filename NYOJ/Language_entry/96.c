#include<stdio.h>
#include<string.h>
int main(void)
{
    int T,i;
    char arr[8];

    scanf("%d",&T);
    getchar(  );
    while(T--)
    {
        scanf("%s",arr);
        for(i = 1;i < strlen(arr);i++)
        {
            if(arr[i] != '0')
            break;
        }
        if(i == strlen(arr))
        {
            printf("0\n");
            continue;
        }
        for(;i < strlen(arr);i++)
        printf("%c",arr[i]);
        printf("\n");
    }
}

/* 此题难度很小.基本就是对于字符串的简单处理
*
* 谨慎注意越界及无数出的情况就好
*
* 下面的样例是使用scanf的特殊修饰符进行处理的
*
* 很有意思,可以借鉴
*
*/

 
#include<cstdio>
int main()
{
	int n,m;
	scanf("%d",&n);
	while(n--)
	{
		scanf("\n%*c%d",&m);
		printf("%d\n",m);
	}
}                
