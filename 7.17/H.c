/*************************************************************************
	> File Name: H.c
	> Author:KVD 
	> Mail:Evilcrow486@gmail.com 
	> Created Time: Mon 17 Jul 2017 02:36:41 PM CST
 ************************************************************************/

#include<stdio.h>
int main(void)
{
    int N;
    int M;
    int t;
    int arr[1000];

    scanf("%d",&N);
    while(N--)
    {
        int sum = 0;
        scanf("%d",&M);
        for(t = 0;t < M;t++)
        {
            scanf("%d",&arr[t]);
            sum+=arr[t];
        }
        if(N == 0)
        {
            printf("%d\n",sum);
            break;
        }
        printf("%d\n\n",sum);
    }

    return 0;
}
