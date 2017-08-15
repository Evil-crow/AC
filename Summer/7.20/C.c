#include<stdio.h>
int main(void)
{
   int T;
   int c,v0,v1,a,l;
   int last,days,flag;

   scanf("%d",&T);
   getchar( );
   while(T--)
   {
      flag = 0;
      scanf("%d %d %d %d %d",&c,&v0,&v1,&a,&l);
      last = 100;

      while(last > 0)
      {
         last = c - v0;
         days = 1;
         if(last <= 0)
         {
            printf("%d\n",days);
            continue;
         }
         if(a != 0)
            while(v0 < v1)
            u
               v0 += a;
                if(v0 > v1)
                v0 = v1;
               last = (last+l)-v0;
               days++;
               if(last <= 0)
               {
                  printf("%d\n",days);
                  flag = 1;
                  break;
               }
            }
         if(flag == 1)
            continue;
         while(last > 0)
         {
            last = (last+l)-v0;
            days++;
         }
         printf("%d\n",days);
      }
   }

   return 0;
}
