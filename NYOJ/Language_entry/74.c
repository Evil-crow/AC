#include<stdio.h>
int main(void)
{
    int m,n,sum;
    int a,b,c,d,e,f;

    scanf("%d %d",&m,&n);
    while(m != 0 && n!= 0)
    {
        sum = 0;
        a = m/100;
        b = m%100/10;
        c = m%100%10;
        d = n/100;
        e = n%100/10;
        f = n%100%10;
        if(c+f >= 10)
        {
            sum++;
            if(b+e+1 >= 10)
            {
                sum++;
                if(a+d+1 >= 10)
                {
                    sum++;
                    printf("%d\n",sum);
                    scanf("%d %d",&m,&n);
                    continue;
                }
                printf("%d\n",sum);
                scanf("%d %d",&m,&n);
                continue;
            }
            printf("%d\n",sum);
            scanf("%d %d",&m,&n);
            continue;
        } 
        if(b+e >= 10)
        {
            sum++;
            if(a+d+1 >= 10)
            {
                sum++;
                printf("%d\n",sum);
                scanf("%d %d",&m,&n);
                continue;
            }
            printf("%d\n",sum);
            scanf("%d %d",&m,&n);
            continue;
        }
        if(a+c >= 10)
        {
            sum++;
            printf("%d\n",sum);
            scanf("%d %d",&m,&n);
            continue;
        }
        printf("%d\n",sum);
        scanf("%d %d",&m,&n);
        continue;
    }
    return 0;
}

/* 本道题,没有用心思考,只是想着尽快解出来
 *
 * 没有认真的研究
 *
 * 所以代码重复度高,很垃圾的代码
 *
 * 下面的题解,很不错,值得学习
 *
 */

  
 
#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,n,m,i;
	for(;;)
	{
		scanf("%d%d",&n,&m);
		if(n==0&&m==0)
			return 0;
		else
		{
			i=0;
			a=n/100;b=n%100/10;c=n%10;
			d=m/100;e=m%100/10;f=m%10;
			if(c+f>=10)
			{i+=1;b+=1;}
			if(b+e>=10)
			{i+=1;a+=1;}
			if(a+d>=10)
			{i+=1;}
			printf("%d\n",i);
		}
	}
  return 0;
}
                
