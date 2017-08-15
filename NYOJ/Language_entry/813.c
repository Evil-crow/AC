#include<stdio.h>
int main(void)
{
    int a,b;
    int i,j,flag,result;

    scanf("%d %d",&a,&b);
    while(a != 0 && b != 0)
    {
        flag = 0;
        for(i = 1;i <= a/2;i++)
        {
            j = a-i;
            result = i*j;
            if(result <= b)
            flag = 1;
        }
        if(flag == 1)
        printf("YES\n");
        else
        printf("NO\n");
        scanf("%d %d",&a,&b);
    }
}
