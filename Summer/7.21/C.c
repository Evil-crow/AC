#include<stdio.h>
int main(void)
{
   int T;
   int num,sum;

   scanf("%d",&T);
   getchar( );
   while(T--)
   {
      scanf("%d",&num);
      sum = 3;
      while(num--)
         sum = (sum - 1)*2;

      printf("%d\n",sum);
   }

   return 0;
}
