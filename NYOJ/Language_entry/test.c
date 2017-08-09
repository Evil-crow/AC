#include<stdio.h>

int judge(int );
int main(void)
{
    int i;
    scanf("%d",&i);
    if(judge(i))
    printf("111111111");
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
