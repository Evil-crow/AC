#include<stdio.h>
int main(void)
{
   int t = 12;
   double num;
   double sum = 0;

   while(t--)
   {
      scanf("%lf",&num);
      sum+=num;
   }
   printf("$%.2lf",sum/12);

   return 0;
}
