/*************************************************************************
	> File Name: B.c
	> Author:KVD 
	> Mail:Evilcrow486@gmail.com 
	> Created Time: Mon 17 Jul 2017 11:34:52 AM CST
 ************************************************************************/

#include<stdio.h>
int main(void)
{
    int N;
    int a,b;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",a+b);
    }

    return 0;
}
