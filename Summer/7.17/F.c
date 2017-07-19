/*************************************************************************
	> File Name: F.c
	> Author:KVD 
	> Mail:Evilcrow486@gmail.com 
	> Created Time: Mon 17 Jul 2017 02:45:40 PM CST
 ************************************************************************/

#include<stdio.h>
int main(void)
{
    int N;
    int t;
    int arr[1000];

    while(scanf("%d",&N) != EOF)
    {
        int sum = 0;
        for(t = 0;t < N;t++)
        {
            scanf("%d",&arr[t]);
            sum+=arr[t];
        }
        printf("%d\n",sum);
    }

    return 0;
}
