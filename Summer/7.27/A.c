#include<stdio.h>
#include<math.h>
int main(void)
{
    double p,q,m,n;
    double sum1,sum2;

    sum1 = 0;sum2 = 0;
    scanf("%lf %lf",&p,&q);
    while(p--)
    {
       scanf("%lf",&m);
       sum1+=m*pow(q,p);
    }

    scanf("%lf %lf",&p,&q);
    while(p--)
    {
       scanf("%lf",&m);
       sum2+=m*pow(q,p);
    }

    if(sum1 == sum2)
    printf("=");
    if(sum1 > sum2)
    printf(">");
    if(sum1 < sum2)
    printf("<");
    printf("\n");
    return 0;
}
