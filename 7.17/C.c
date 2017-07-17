/*************************************************************************
	> File Name: C.c
	> Author:KVD 
	> Mail:Evilcrow486@gmail.com 
	> Created Time: Mon 17 Jul 2017 11:37:49 AM CST
 ************************************************************************/

#include<stdio.h>
int main(void)
{
    int a,b;
    a = 1;
    b = 1;

    while(1)
    {
        scanf("%d %d",&a,&b);
        if(a == 0 && b == 0)
        break;
        printf("%d\n",a+b);
    }

    return 0;
}
