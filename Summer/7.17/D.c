/*************************************************************************
	> File Name: D.c
	> Author:KVD 
	> Mail:Evilcrow486@gmail.com 
	> Created Time: Mon 17 Jul 2017 11:40:51 AM CST
 ************************************************************************/

#include<stdio.h>
int main(void)
{
    int N;
    int t;
    int arr[1000];
    while(1)
    {
        int sum = 0;
        scanf("%d",&N);
        if(N == 0)
        break;
        for(t = 0;t < N;t++)
        {
            scanf("%d",&arr[t]);
        }
        for(t = 0;t < N;t++)
        sum+=arr[t];

        printf("%d\n",sum);
    }

    return 0;
}
