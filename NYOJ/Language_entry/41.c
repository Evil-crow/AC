#include<stdio.h>
int main(void)
{
    int a[3];
    int i,j,temp;
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    for(j = 0;j < 2;j++)
        for(i = 0;i < 2;i++)
        {
            if(a[i] > a[i+1])
            {
                temp  = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
    printf("%d %d %d",a[0],a[1],a[2]);

    return 0;
}

/* 活锤子,连最简单的题都写错了
 *
 * 冒泡排序,1.不能越界
 *
 * 2.if的判断记得加上括号
 *
 * 哎,恶贼,nao锤子
 *
 */
 
#include <stdio.h>
int main()
{
	int a,b,c,an[3],i,t,j,max,flag;
	scanf ("%d %d %d",&an[0],&an[1],&an[2]);
	for (i=0;i<3;i++)
	{
		t=max=an[i];
		flag=i;
		for (j=i;j<3;j++)
			if (an[j]>t) 
			{
				max=an[j];
				flag=j;
			};
		t=an[i];
		an[i]=max;
		an[flag]=t;
	}
	for (i=2;i>=0;i--)
		printf ("%d ",an[i]);
	return 0;
}
        

