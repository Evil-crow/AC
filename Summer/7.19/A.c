/*************************************************************************
	> File Name: A.c
	> Author: 
	> Mail: 
	> Created Time: Wed 19 Jul 2017 10:55:50 AM CST
 ************************************************************************/

#include<stdio.h>
int main(void)
{
    int arr[1000];
    int n;

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    for(n = 3;n < 1000;n++)
    {
        arr[n] = arr[n-1]+arr[n-3];
    }
    scanf("%d",&n);
    while(n != 0)
    {
        printf("%d\n",arr[n-1]);
        scanf("%d",&n);
    }

    return 0;
}
