#include<stdio.h>
int main(void)
{
    int T;
    int n,k,sum;

    scanf("%d",&T);
    getchar(  );
    while(T--)
    {
        scanf("%d %d",&n,&k);
        sum = n;
        while(n >= k)
        {
            sum+=n/k;
            n = n/k+n%k;
        }
        printf("%d\n",sum);
    }

    return 0;
}

/* 此题注意,最后一个样例有问题,所以,
*
* 不能过分迷信样例输出
*
* 结合生活经验,此题易解
*
*/

 
#include "stdio.h"
#include<fstream>
int main()
{
	//freopen("d:\\1.txt","r",stdin);
	//freopen("d:\\2.txt","w",stdout);
	int m;
	scanf("%d",&m);
    while(m--)
	{
		int n,k,sum;
		scanf("%d%d",&n,&k);
		sum=n;
		while(n/k)                   
		{ sum+=n/k;  n=n/k+n%k; }
		printf("%d\n",sum);
	}
	return 0;
}        
