#include <stdio.h>
int main(void)
{
    int n;                         //保存矩阵维数
    int num,sum;                   //矩阵中填数
    int i,j,k;                       //下标操作

    scanf("%d",&n);
    getchar(  );
    int arr[n][n];
    num = 1;
    k = n;
    for(i = 0,j = n-1;i < n;i++)
        arr[i][j] = num++;
    for(i = n-1,j = n-2;j >= 0;j--)
        arr[i][j] = num++;
    for(i = n-2,j = 0;i >= 0;i--)
        arr[i][j] = num++;
    for(;num <= k*k+1;)
    {
        n--;
        printf("%d\n",n);
        i++;
        j++;
        for(;j < n;j++)
            arr[i][j] = num++;
        if(num == k*k+1)
        break;
        i++;
        j--;
        for(;i < n;i++)
            arr[i][j] = num++;
        if(num == k*k+1)
        break;
        i--;
        j--;
        n--;
        printf("%d\n",n);
        for(;j >= 0;j--)
            arr[i][j] = num++;
        if(num == k*k+1)
        break;
        j++;
        i--;
        for(;i >= 0;i--)
            arr[i][j] = num++;
    }
    for(i = 0;i < k;i++)
    {
        for(j = 0;j < k;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }

    return 0;
}
