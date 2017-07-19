#include<stdio.h>
int main(void)
{
   int M;
   int N;
   int t;
   int arr[1000];

   scanf("%d",&N);
   while(N--)
   {
     int sum = 0;
     scanf("%d",&M);
     for(t = 0;t < M;t++)
     {     
	    scanf("%d",&arr[t]);
        sum+=arr[t];
     }
     printf("%d\n",sum);
   }

   return 0;
}
