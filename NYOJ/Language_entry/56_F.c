#include<stdio.h>
#include<math.h>
int judge(int );
int main(void)
{
    int T;
    int m,n,i,sum;

    scanf("%d",&T);
    getchar( );
    while(T--)
    {
        scanf("%d %d",&n,&m);
        while(n > 0)
        {
            for(i = 0;i < n;i++)
            {
                if(judge(i) && i == m)
                sum++;
            }
        }
        printf("%d\n",sum);
    }
}

int judge(int n)
{
    int t,flag;
    flag = 1;
    for(t = 2;t < sqrt(n);t++)
    {
        if(n%t == 0)
        flag = 0;
    }
    return flag;
}
