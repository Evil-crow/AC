//此题解法错误,很失败..

#include<stdio.h>
int main(void)
{
   int T,sum;
   int c,v0,v1,a,l,day;

   scanf("%d",&T);
   getchar( );
   while(T--)
   {
      day = 0;
      scanf("%d %d %d %d %d",&c,&v0,&v1,&a,&l);
      if(c-v0 == 0)
      {
         printf("1\n");
         continue;
      }
      while(1)
      {
       if(a != 0 && v0 < v1)
       {
          v0 = a*day+v0;
          sum+=v0-l;
          day++;
       }
       else
       {
          sum+=v0-l;
          day++;
       }

       if(sum >= c)
          break;
      }
      printf("%d\n",day);
   }

   return 0;
}
