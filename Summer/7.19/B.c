/*************************************************************************
	> File Name: B.c
	> Author: 
	> Mail: 
	> Created Time: Wed 19 Jul 2017 09:40:57 AM CST
 ************************************************************************/

#include<stdio.h>
long long seek(long long , long long );
int main(void)
{
    long long n, t;
    long long result;
    long long arr[1000];

    while(scanf("%d",&n) != EOF)
    {
        for(t = 0;t < n;t++)
        scanf("%d",&arr[t]);
        result = arr[0];
        for(t = 0;t < n;t++)
        {
            result = seek(result,arr[t]);
        }
        
        printf("%d\n",result);
    }

    return 0;
}

long long seek(long long n,long long m)
{
    long long num;
    long long i, j;
    i = n;
    j = m;

    while(j != 0)
    {
        num = i%j;
        i = j;
        j = num;
    }
    
    return (n*m)/i;
}
