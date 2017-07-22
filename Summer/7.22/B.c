#include<stdio.h>
int main(void)
{
   int T;
   int m,n,sum;

   scanf("%d",&T);
   getchar( );
   while(T--)
   {
      scanf("%d %d",&m,&n);
      m = m%100;
      n = n%100;
      sum = m + n;
      sum = sum%100;
      printf("%d\n",sum);
   }

   return 0;
}
