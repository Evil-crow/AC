/*************************************************************************
	> File Name: 2.c
	> Author:KVD
	> Mail:Evilcrow486@gmail.com
	> Created Time: 2017年06月17日 星期六 16时11分25秒
 ************************************************************************/

#include<stdio.h>
int line(int );
void result(int ,int );
int main(void)
{
    int x, y;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&x,&y);
        int temp = line(x);
        result(temp,y);
    }

    return 0;
}
int line(int t)
{
    int sum = 0;
    int i = 1;
    while(sum != t)
    {
        sum+=i;
        i++;
    }

    return i-1;
}

void result(int p,int k)
{
    int i, j,flag;
    int sum1,sum2,sum3,sum4;
    flag = 0;
    for(i = 1;i <= p-3;i++)
    {
        for(j = i+2;j <= p-1;j++)
        {
            sum1 = i*(i-1)/2;
            sum2 = (i+j+1)*(j-i-2)/2;
            sum3 = (j+p+2)*(p-j-1)/2;
            sum4 = i*(i+1)+j*(j+1);
            if(sum1+sum2+sum3+sum4 == k)
            {
                printf("(%d,%d)",i,j);
                flag++;
            }
        }
    }
    if(flag == 0)
    printf("NONE");
    printf("\n");
}
