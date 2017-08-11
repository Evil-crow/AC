#include<stdio.h>
int main(void)
{
    int T,a,b,c,sum;
    int month[12] ={31,28,31,30,31,30,31,31,30,31,30,31}; 

    scanf("%d",&T);
    getchar(  );
    while(T--)
    {
        sum = 0;
        scanf("%d %d %d",&a,&b,&c);
        if(a%4 == 0)
        month[1] = 29;
        for(int i = 0;i < b-1;i++)
        sum+=month[i];
        printf("%d\n",sum+c);
        month[1] = 28;
    }

    return 0;
}

/* 在这道题上,我觉得比题解简单许多
 *
 * 这种题,就可以偷鸡了
 *
 * 直接使用数组,方便许多
 *
 * 但是要注意闰年的问题
 *
 * 不能随便+1,而应该修改数组的元素
 *
 */
 
#include<stdio.h>
int main()
{
	int a,b=0,c,y,m,d,fib;
	scanf("%d",&a);
	while(a--)
	{
		scanf("%d %d %d",&y,&m,&d);
		if(y%400==0||y%100!=0&&y%4==0)
			fib=29;
		else fib=28;
		for(c=1;c<=m;c++)
		switch(c-1)
		{
           case 1:
		   case 3:
		   case 5:
		   case 7:
		   case 8:
		   case 10:b+=31;break;
		   case 2:b+=fib;break;
		   case 4:
		   case 6:
		   case 9:
		   case 11:b+=30;break;
		}
		b+=d;
		printf("%d\n",b);
		b=0;
	}
	return 0;
}        
