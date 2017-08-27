#include<stdio.h>
int main(void)
{
    int M,n;
    int i,j;

    scanf("%d",&M);
    getchar(  );
    while(M--)
    {
        scanf("%d",&n);
        for(i = 1;i <= n;i++)
        {
            for(j = i;j <= 9;j++)
                printf("%d*%d=%d ",i,j,i*j);
            printf("\n");
        }
        printf("\n");
    }
    
    return 0;
}


/* TM,当年困死劳资的题,现在也是秒解,下面
 *
 * 的C++解法也是五五
 *
 */

 
#include<stdio.h>
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=i;j<10;j++)
				printf("%d*%d=%d ",i,j,i*j);
			printf("\n");
		}
	}
}        
