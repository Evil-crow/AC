/*************************************************************************
	> File Name: A.c
	> Author: 
	> Mail: 
	> Created Time: Thu 20 Jul 2017 08:10:20 AM CST
 ************************************************************************/

#include<stdio.h>
int main(void)
{
    int m, n;
    int i;
    int a, b, c;
    int num;

    while(scanf("%d %d",&m,&n) != EOF)
    {
        num = 0;
        for(i = m;i <= n;i++)
        {
            a = i%100%10;
            b = i%100/10;
            c = i/100;
            if(i == (a*a*a + b*b*b + c*c*c))
            {
                num++;
                if(num == 1)
                printf("%d",i);
                else
                printf(" %d",i);
            }
        }
        if(num == 0)
        printf("no");
        printf("\n");
    }

    return 0;
}
