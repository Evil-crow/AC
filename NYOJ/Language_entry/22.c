#include <stdio.h>
#include<string.h>
int judge(int );
int main(int argc,char **argv)
{
    int M,N,i,j,sum;
    int arr[1000];

    scanf("%d",&M);
    while(M--)
    {
        memset(arr,0,1000);
        sum = 0;
        scanf("%d",&N);
        getchar(  );
        for(i = 0;i < N;i++)
            scanf("%d",&arr[i]);
        j = i;
        for(i = 0;i < j;i++)
        {
            if(arr[i] == 1)
            continue;
            if(judge(arr[i]))
                sum+=arr[i];
            else
            continue;
        }
        printf("%d\n",sum);
    }

    return 0;
}

int judge(int n)
{
    int i,flag;
    flag = 0;
    for(i = 2;i < n;i++)
    {
        if(n%i == 0)
        flag = 1;
        else
        continue;
    }
    if(flag == 1)
    return 0;
    else
    return 1;
}



/* 此处以下为最优解,整体思路相同,
 *
 * 但是在对于素数判断上,这种处理方法更为老练
 *
 * 直接进行遍历,至sqrt(  )显然更为方便
 *
 * 活学活用,值得学习,写出简单优美的代码
 *
 */
#include<stdio.h>
#include <math.h>
int main()
{
	int m,n,i,j,a[1000],flag=0;
	long s;
	scanf("%d",&m);
	while(m--)
	{
		s=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		for(i=0;i<n;i++)
		{
			if(a[i]==1)	continue;
			flag=0;
			for(j=2;j<=sqrt(a[i]);j++)
			{
				if(a[i]%j==0)
				{flag=1;break;}			
			}
			if(flag==0)	s+=a[i];
		}
	printf("%d\n",s);
	}
	return 0;
}        
