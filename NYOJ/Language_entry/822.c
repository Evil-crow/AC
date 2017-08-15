#include<stdio.h>
int main(void)
{
    int i, j, t;
    scanf("%d",&t);
    getchar(  );
    for(i = 1;i <= t;i++)
    {
        for(j = 1;j <= t;j++)
        printf("*");
        printf("\n");
    }

    return 0;
}

//只是为了刷题量
