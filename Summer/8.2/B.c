#include<stdio.h>
int main(int argc,char **argv)
{
    int T;
    int price;
    int num,sum;

    scanf("%d",&T);
    while(T != 0)
    {
        sum = 0;
        while(T--)
        {
            num = 0;
            scanf("%d",&price);
            num+=price/100;
            num+=price%100/50;
            num+=price%100%50/10;
            num+=price%100%50%10/5;
            num+=price%100%50%10%5/2;
            num+=price%100%50%10%5%2/1;
            sum+=num;
        }
        printf("%d\n",sum);
        scanf("%d",&T);
    }

    return 0;
}
