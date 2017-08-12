#include<stdio.h>
int main(void)
{
    int N;
    int i,j,t,sum;
    int arr[100];

    scanf("%d",&N);
    getchar(  );
    for(i = 1;i <= N;i++)
    {
        t = 0;
        sum = 0;
        for(j = 1;j <= i;j++)
        {
            if(i%j == 0)
            {
                arr[t++] = j;
                sum+=j;
            }
        }
        if(sum == i)
        {
            printf("%d its factor are");
            for(j = 0;j < t;j++)
            printf(" %d",arr[j]);
        }
        printf("\n");
    }
}
