/*************************************************************************
	> File Name: C.c
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Jul 2017 02:29:05 PM CST
 ************************************************************************/

#include<stdio.h>
int main(void)
{
    int n, m;
    int sum;
    int i, j, t;
    int arr[100];
    while(scanf("%d %d",&n,&m) != EOF)
    {
        for(i = 0,t = 0;i < n;i++,t++)
        {
            arr[t] = 2*(i+1);
        }
        for(i = 0;i < n;i++)
        {
            sum = 0;
            if(i+m > n)
            {
                for(j = 0;j < n%m;j++)
                {
                    sum+=arr[i];
                    i++;
                }
                i--;
                printf("%d\n",sum/(n%m));
            }
            else
            {
                for(j = 0;j < m;j++)
                {
                    sum+=arr[i];
                    i++;
                }
                i--;
                if((i+1) < n)
                printf("%d ",sum/m);
                else
                printf("%d\n",sum/m);
            }
        }
    }

    return 0;
}
