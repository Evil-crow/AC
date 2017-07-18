/*************************************************************************
	> File Name: B.c
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Jul 2017 02:17:54 PM CST
 ************************************************************************/

#include<stdio.h>
int main(void)
{
    int N;
    int arr[100];
    int t;
    int sum,max,min;
    float average;

    while(scanf("%d",&N) != EOF || N<=2 || N>100)
    {
        max = -1;
        min = 100;
        sum = 0;
        for(t = 0;t < N;t++)
        {
            scanf("%d",&arr[t]);
            if(arr[t] > max)
            max = arr[t];
            if(arr[t] < min)
            min = arr[t];
            sum+=arr[t];
        }
        sum = sum-min-max;
        average =(float)sum/(N-2);
        printf("%.2f\n",average);
    }

    return 0;
}
